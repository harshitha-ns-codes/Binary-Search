#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int low = 1, high = n / 2;
    int ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Square root (floor) of " << n << " is: " << ans << endl;
    return 0;
}

