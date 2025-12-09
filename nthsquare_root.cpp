#include <iostream>
using namespace std;

// Returns:
// 2 -> mid^n > m
// 1 -> mid^n == m
// 0 -> mid^n < m
int powerCompare(long long mid, int n, long long m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;

        if (ans > m) {
            return 2; // mid^n is greater than m
        }
    }

    if (ans == m) return 1; // exactly equal
    return 0;               // mid^n is less than m
}

// Finds integer nth root of m, or returns -1 if it doesn't exist
int nthRoot(int n, long long m) {
    long long low = 1, high = m;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        int midN = powerCompare(mid, n, m);

        if (midN == 1) {
            return (int)mid; // found exact nth root
        } else if (midN == 0) {
            // mid^n < m → move right
            low = mid + 1;
        } else {
            // mid^n > m → move left
            high = mid - 1;
        }
    }

    return -1; // no integer nth root
}

int main() {
    int n;
    long long m;

    cout << "Enter n and m (find integer nth root of m): ";
    cin >> n >> m;

    int result = nthRoot(n, m);
    cout << result << endl;

    return 0;
}
