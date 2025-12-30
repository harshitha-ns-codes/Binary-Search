#include <bits/stdc++.h>
using namespace std;

// Function to check if we can place 'cows' cows
// with at least 'dist' distance between them
bool canWePlace(vector<int> &stall, int dist, int cows)
{
    int cntCows = 1;          // place first cow at first stall
    int last = stall[0];

    for (int i = 1; i < stall.size(); i++)
    {
        if (stall[i] - last >= dist)
        {
            cntCows++;
            last = stall[i];
        }

        if (cntCows >= cows)
            return true;
    }
    return false;
}

int main()
{
    int n, cows;
    cin >> n >> cows;

    vector<int> stall(n);
    for (int i = 0; i < n; i++)
        cin >> stall[i];

    sort(stall.begin(), stall.end());

    int low = 1;
    int high = stall[n - 1] - stall[0];
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canWePlace(stall, mid, cows))
        {
            ans = mid;       // store answer
            low = mid + 1;   // try for bigger distance
        }
        else
        {
            high = mid - 1;  // reduce distance
        }
    }

    cout << ans << endl;
    return 0;
}
