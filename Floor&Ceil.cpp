#include <iostream>
using namespace std;

int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1; // default: no floor found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            ans = mid;
            high = mid - 1; // search right for closer floor
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1; // default: no ceil found

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

    cout << "Enter value: ";
    cin >> x;

    int floorIndex = findFloor(arr, n, x);
    int ceilIndex = findCeil(arr, n, x);

    if (floorIndex == -1)
        cout << "Floor: Not available\n";
    else
        cout << "Floor: " << arr[floorIndex] << endl;

    if (ceilIndex == -1)
        cout << "Ceil: Not available\n";
    else
        cout << "Ceil: " << arr[ceilIndex] << endl;

    return 0;
}
