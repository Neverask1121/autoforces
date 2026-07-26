"""
Codeforces Auto-Pusher: Automatically push accepted Codeforces solutions to GitHub.

Uses the Codeforces API to fetch accepted submissions
and the GitHub API (PyGithub) to push them to a repository.
"""

import base64
import hashlib
import json
import os
import random
import re
import string
import sys
import time
from typing import Dict, List, Optional, Set

import requests
from github import Auth, Github, GithubException, InputGitTreeElement

# ── Configuration from environment variables ──────────────────────────────────

CF_API_KEY = os.environ.get("CF_API_KEY", "")
CF_API_SECRET = os.environ.get("CF_API_SECRET", "")
CF_HANDLE = os.environ.get("CF_HANDLE", "")
GITHUB_TOKEN = os.environ.get("GITHUB_TOKEN", "")
GITHUB_REPO = os.environ.get("GITHUB_REPO", "")  # e.g. "MontassarBr/ProblemSolving"
GITHUB_TARGET_DIR = os.environ.get("GITHUB_TARGET_DIR", "CodeForces")  # subfolder in the repo

CF_API_BASE = "https://codeforces.com/api"
STATE_FILE = f"{GITHUB_TARGET_DIR}/pushed.json" if GITHUB_TARGET_DIR else "pushed.json"
BATCH_SIZE = 50  # max files per commit to avoid GitHub API limits

# ── Language → file extension mapping ─────────────────────────────────────────

LANG_EXT_MAP = {
    "GNU C": ".c",
    "GNU C11": ".c",
    "GNU C17": ".c",
    "C": ".c",
    "GNU C++": ".cpp",
    "GNU C++0x": ".cpp",
    "GNU C++11": ".cpp",
    "GNU C++14": ".cpp",
    "GNU C++17": ".cpp",
    "GNU C++17 (64)": ".cpp",
    "GNU C++20 (64)": ".cpp",
    "GNU C++23 (64)": ".cpp",
    "C++17 (GCC 7-32)": ".cpp",
    "C++20 (GCC 13-64)": ".cpp",
    "C++23 (GCC 14-64, msys2)": ".cpp",
    "Clang++17 Diagnostics": ".cpp",
    "Clang++20 Diagnostics": ".cpp",
    "Microsoft Visual C++ 2017": ".cpp",
    "Microsoft Visual C++ 2010": ".cpp",
    "C# 8": ".cs",
    "C# 10": ".cs",
    "C# Mono": ".cs",
    "Mono C#": ".cs",
    "D": ".d",
    "Go": ".go",
    "Haskell": ".hs",
    "Java 8": ".java",
    "Java 11": ".java",
    "Java 17": ".java",
    "Java 21": ".java",
    "Kotlin 1.4": ".kt",
    "Kotlin 1.5": ".kt",
    "Kotlin 1.6": ".kt",
    "Kotlin 1.7": ".kt",
    "Kotlin 1.9": ".kt",
    "OCaml": ".ml",
    "Delphi": ".pas",
    "FPC": ".pas",
    "Pascal": ".pas",
    "Perl": ".pl",
    "PHP": ".php",
    "Python 2": ".py",
    "Python 3": ".py",
    "PyPy 2": ".py",
    "PyPy 2-64": ".py",
    "PyPy 3": ".py",
    "PyPy 3-64": ".py",
    "Ruby 3": ".rb",
    "Ruby": ".rb",
    "Rust": ".rs",
    "Rust 2021": ".rs",
    "Scala": ".scala",
    "JavaScript": ".js",
    "Node.js": ".js",
    "TypeScript": ".ts",
    "Tcl": ".tcl",
    "Io": ".io",
    "Pike": ".pike",
    "Befunge": ".bf",
    "Cobol": ".cob",
    "Factor": ".factor",
    "Secret_171": ".txt",
    "Roco": ".txt",
    "Ada": ".adb",
    "Mysterious Language": ".txt",
    "FALSE": ".f",
    "Picat": ".pi",
    "Clojure": ".clj",
    "Julia": ".jl",
}


def get_extension(language: str) -> str:
    """Map Codeforces programming language string to a file extension."""
    # Try exact match first
    if language in LANG_EXT_MAP:
        return LANG_EXT_MAP[language]
    # Try partial match: CF language string contains a known key
    lang_lower = language.lower()
    for key, ext in LANG_EXT_MAP.items():
        key_lower = key.lower()
        # Only match if the key is a substantial substring (3+ chars)
        if len(key_lower) >= 3 and (key_lower in lang_lower or lang_lower in key_lower):
            return ext
    # Default
    return ".txt"


def sanitize(name: str) -> str:
    """Sanitize a string for use as a file/folder name."""
    # Replace characters not safe for file paths
    name = re.sub(r'[<>:"/\\|?*.]', "_", name)
    # Collapse multiple underscores/spaces
    name = re.sub(r"[\s_]+", "_", name)
    # Strip leading/trailing underscores and dots
    name = name.strip("_. ")
    return name if name else "Unknown"


# ── Codeforces API (authenticated) ────────────────────────────────────────────


def cf_api_request(method: str, params: Optional[Dict] = None) -> dict:
    """
    Make an authenticated request to the Codeforces API.

    Builds the apiSig as described in https://codeforces.com/apiHelp:
      apiSig = rand + sha512hex(rand/method?sorted_params#secret)
    """
    if params is None:
        params = {}

    rand_prefix = "".join(random.choices(string.ascii_lowercase + string.digits, k=6))
    current_time = str(int(time.time()))

    # Add auth params
    params["apiKey"] = CF_API_KEY
    params["time"] = current_time

    # Sort params lexicographically by (key, value)
    sorted_params = sorted(params.items())
    param_string = "&".join(f"{k}={v}" for k, v in sorted_params)

    # Build the string to hash: rand/methodName?sorted_params#secret
    sig_input = f"{rand_prefix}/{method}?{param_string}#{CF_API_SECRET}"
    sig_hash = hashlib.sha512(sig_input.encode("utf-8")).hexdigest()
    api_sig = rand_prefix + sig_hash

    params["apiSig"] = api_sig

    url = f"{CF_API_BASE}/{method}"
    resp = requests.get(url, params=params, timeout=30)

    # Debug: check for auth errors before raise_for_status
    if resp.status_code != 200:
        print(f"    API call {method} returned status {resp.status_code}")
        try:
            err_data = resp.json()
            print(f"    Response: {err_data}")
        except Exception:
            print(f"    Response text: {resp.text[:300]}")

    resp.raise_for_status()
    data = resp.json()

    if data.get("status") != "OK":
        raise RuntimeError(f"Codeforces API error: {data.get('comment', 'Unknown error')}")

    return data["result"]


def verify_api_auth():
    """Verify that the API key is working by calling user.friends (requires auth)."""
    print("  Verifying API authentication...")
    try:
        cf_api_request("user.friends", {"onlyOnline": "false"})
        print("  API key is valid and authenticated!")
        return True
    except Exception as e:
        print(f"  ERROR: API authentication failed: {e}")
        print(f"  API Key (first 8 chars): {CF_API_KEY[:8]}...")
        print(f"  API Secret set: {'yes' if CF_API_SECRET else 'NO - EMPTY!'}")
        print("  Make sure CF_API_KEY and CF_API_SECRET secrets are set correctly.")
        print("  Generate them at: https://codeforces.com/settings/api")
        return False


def fetch_accepted_submissions() -> List[dict]:
    """Fetch all accepted submissions for the configured handle, with source code."""
    all_submissions = []
    page = 1
    page_size = 1000

    while True:
        print(f"  Fetching submissions page {page} (from={((page - 1) * page_size) + 1})...")
        result = cf_api_request("user.status", {
            "handle": CF_HANDLE,
            "from": str(((page - 1) * page_size) + 1),
            "count": str(page_size),
            "includeSources": "true",
        })

        if not result:
            break

        all_submissions.extend(result)

        if len(result) < page_size:
            break

        page += 1
        time.sleep(2)  # respect CF rate limit: 1 req per 2 seconds

    # Filter for accepted (verdict == "OK")
    accepted = [s for s in all_submissions if s.get("verdict") == "OK"]
    print(f"  Found {len(accepted)} accepted submissions out of {len(all_submissions)} total.")

    # Check how many have source code from the API
    with_source = sum(1 for s in accepted if s.get("sourceBase64"))
    print(f"  Submissions with source code from API: {with_source}/{len(accepted)}")

    return accepted


def fetch_contest_names() -> Dict[int, str]:
    """Fetch contest list and return a mapping of contestId → contest name."""
    print("  Fetching contest list for name mapping...")
    contests = cf_api_request("contest.list", {"gym": "false"})
    time.sleep(2)
    mapping = {}
    for c in contests:
        mapping[c["id"]] = c.get("name", f"Contest_{c['id']}")
    return mapping


# ── GitHub operations ─────────────────────────────────────────────────────────


def load_pushed_state(repo) -> Set[int]:
    """Load the set of already-pushed submission IDs from pushed.json in the repo."""
    try:
        contents = repo.get_contents(STATE_FILE)
        data = json.loads(contents.decoded_content.decode("utf-8"))
        return set(data.get("pushed_ids", []))
    except GithubException:
        return set()


def save_pushed_state(repo, pushed_ids: Set[int], branch: str):
    """Save the set of pushed submission IDs to pushed.json in the repo."""
    content = json.dumps({"pushed_ids": sorted(pushed_ids)}, indent=2)
    try:
        existing = repo.get_contents(STATE_FILE, ref=branch)
        repo.update_file(
            STATE_FILE,
            "Update pushed.json",
            content,
            existing.sha,
            branch=branch,
        )
    except GithubException:
        repo.create_file(
            STATE_FILE,
            "Initialize pushed.json",
            content,
            branch=branch,
        )


def batch_commit_files(repo, file_dict: Dict[str, str], message: str, branch: str):
    """
    Create a single commit with multiple files using the Git Data API.
    file_dict: {path: content, ...}
    """
    if not file_dict:
        return

    ref = repo.get_git_ref(f"heads/{branch}")
    latest_commit = repo.get_git_commit(ref.object.sha)
    base_tree = latest_commit.tree

    tree_elements = []
    for path, content in file_dict.items():
        blob = repo.create_git_blob(content, "utf-8")
        tree_elements.append(InputGitTreeElement(
            path=path,
            mode="100644",
            type="blob",
            sha=blob.sha,
        ))

    new_tree = repo.create_git_tree(tree_elements, base_tree)
    new_commit = repo.create_git_commit(message, new_tree, [latest_commit])
    ref.edit(new_commit.sha)


# ── Deduplication: keep only the latest accepted per problem ──────────────────


def deduplicate_submissions(submissions: List[dict]) -> List[dict]:
    """
    Given a list of accepted submissions, keep only the latest one per problem.
    A problem is identified by (contestId, index).
    """
    best = {}
    for sub in submissions:
        problem = sub.get("problem", {})
        contest_id = sub.get("contestId") or problem.get("contestId")
        index = problem.get("index", "")
        key = (contest_id, index)

        if key not in best or sub["id"] > best[key]["id"]:
            best[key] = sub

    return list(best.values())


# ── Build file path for a submission ──────────────────────────────────────────


def build_file_path(sub: dict, contest_names: Dict[int, str]) -> str:
    """Build the repo file path for a submission."""
    problem = sub.get("problem", {})
    contest_id = sub.get("contestId") or problem.get("contestId")
    index = problem.get("index", "X")
    problem_name = problem.get("name", "Unknown")
    language = sub.get("programmingLanguage", "Unknown")

    contest_name = contest_names.get(contest_id, f"Contest_{contest_id}")
    folder = sanitize(f"{contest_name}_{contest_id}")
    filename = sanitize(f"{index}_{problem_name}") + get_extension(language)

    path = f"{folder}/{filename}"
    if GITHUB_TARGET_DIR:
        path = f"{GITHUB_TARGET_DIR}/{path}"
    return path




# ── Main logic ────────────────────────────────────────────────────────────────


def validate_config():
    """Validate that all required environment variables are set."""
    missing = []
    for var in ["CF_API_KEY", "CF_API_SECRET", "CF_HANDLE",
                "GITHUB_TOKEN", "GITHUB_REPO"]:
        if not os.environ.get(var):
            missing.append(var)
    if missing:
        print(f"Error: Missing required environment variables: {', '.join(missing)}")
        print("See .env.example for the required variables.")
        sys.exit(1)


def main():
    validate_config()

    print(f"=== Codeforces AutoPush ===")
    print(f"Handle: {CF_HANDLE}")
    print(f"Target repo: {GITHUB_REPO}")
    print(f"Target dir: {GITHUB_TARGET_DIR or '(root)'}")
    print()

    # 1. Connect to GitHub
    print("[1/6] Connecting to GitHub...")
    gh = Github(auth=Auth.Token(GITHUB_TOKEN))
    repo = gh.get_repo(GITHUB_REPO)
    default_branch = repo.default_branch
    print(f"  Connected. Default branch: {default_branch}")

    # 2. Verify API authentication
    print("[2/6] Verifying Codeforces API auth...")
    if not verify_api_auth():
        sys.exit(1)

    # 3. Load already-pushed state
    print("[3/7] Loading pushed state...")
    pushed_ids = load_pushed_state(repo)
    print(f"  Already pushed: {len(pushed_ids)} submissions")

    # 4. Fetch accepted submissions from Codeforces (with source code via API)
    print("[4/7] Fetching accepted submissions from Codeforces...")
    accepted = fetch_accepted_submissions()

    if not accepted:
        print("  No accepted submissions found. Exiting.")
        print("  (Check that CF_HANDLE is correct and the API key belongs to this account)")
        return

    # Deduplicate: keep only the latest AC per problem
    unique = deduplicate_submissions(accepted)
    print(f"  Unique problems solved: {len(unique)}")

    # Filter out already-pushed
    new_submissions = [s for s in unique if s["id"] not in pushed_ids]
    print(f"  New submissions to push: {len(new_submissions)}")

    if not new_submissions:
        print("  Everything is up to date. Nothing to push.")
        return

    # 5. Fetch contest names for better folder naming
    print("[5/7] Fetching contest names...")
    contest_names = fetch_contest_names()

    # 6. Build file map from API source code
    print(f"[6/7] Building file map for {len(new_submissions)} submissions...")
    file_map = {}  # path -> content
    newly_pushed = set()
    skipped = 0

    for sub in new_submissions:
        b64 = sub.get("sourceBase64", "")
        if b64:
            try:
                source = base64.b64decode(b64).decode("utf-8", errors="replace")
            except Exception:
                source = None
        else:
            source = None

        if source:
            path = build_file_path(sub, contest_names)
            file_map[path] = source
            newly_pushed.add(sub["id"])
        else:
            problem = sub.get("problem", {})
            index = problem.get("index", "?")
            name = problem.get("name", "?")
            print(f"    Skipped {index}. {name} (no source in API response)")
            skipped += 1

    print(f"  Built: {len(file_map)} files, Skipped: {skipped}")

    if not file_map:
        print("  ERROR: No source code could be fetched.")
        print("  Make sure the API key belongs to the same account as CF_HANDLE.")
        print("  (includeSources only works for your own account)")
        sys.exit(1)

    # 7. Push to GitHub in batches
    print(f"[7/7] Pushing {len(file_map)} files to GitHub...")
    all_paths = list(file_map.keys())

    for batch_start in range(0, len(all_paths), BATCH_SIZE):
        batch_paths = all_paths[batch_start:batch_start + BATCH_SIZE]
        batch = {p: file_map[p] for p in batch_paths}
        batch_num = (batch_start // BATCH_SIZE) + 1
        total_batches = (len(all_paths) + BATCH_SIZE - 1) // BATCH_SIZE

        if total_batches == 1:
            msg = f"Add {len(newly_pushed)} accepted solutions"
        else:
            msg = f"Add solutions (batch {batch_num}/{total_batches})"

        print(f"  Committing batch {batch_num}/{total_batches} ({len(batch)} files)...")
        batch_commit_files(repo, batch, msg, default_branch)

    # Update pushed state
    pushed_ids.update(newly_pushed)
    save_pushed_state(repo, pushed_ids, default_branch)

    print()
    print(f"Done! Pushed {len(newly_pushed)} new solutions to {GITHUB_REPO}.")
    print(f"Total pushed: {len(pushed_ids)} submissions.")


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(f"\nFATAL ERROR: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)