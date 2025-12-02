#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; 

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    int index = lowerBound(arr, n, x);

    if (index == n)
        cout << "No element found greater than or equal to " << x << endl;
    else
        cout << "Lower bound index = " << index << ", Value = " << arr[index] << endl;

    return 0;
}
