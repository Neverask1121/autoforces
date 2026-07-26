#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    
    // Read the heights of soldiers
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Find the maximum height
    int max_height = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_height) {
            max_height = arr[i];
        }
    }
    
    // Find the minimum height
    int min_height = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_height) {
            min_height = arr[i];
        }
    }
    
    // Find the LEFTMOST position of maximum height
    int pos_max = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == max_height) {
            pos_max = i;
            break;
        }
    }
    
    // Find the RIGHTMOST position of minimum height
    int pos_min = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == min_height) {
            pos_min = i;
            break;
        }
    }
    
    // Calculate minimum swaps needed
    int swaps = pos_max + (n - 1 - pos_min);
    
    // If max is to the right of min, subtract 1
    if (pos_max > pos_min) {
        swaps--;
    }
    
    cout << swaps << endl;
    
    return 0;
}