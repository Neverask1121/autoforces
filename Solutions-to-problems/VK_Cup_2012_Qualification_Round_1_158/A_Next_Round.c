#include <stdio.h>

int main(void)
{
    int n, k;
    int a[50];          // n ≤ 50

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int cutoff = a[k - 1];   // score of k-th place
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= cutoff && a[i] > 0)
            count++;
        else
            break;           // scores are non-increasing, so we can stop
    }

    printf("%d\n", count);
    return 0;
}
