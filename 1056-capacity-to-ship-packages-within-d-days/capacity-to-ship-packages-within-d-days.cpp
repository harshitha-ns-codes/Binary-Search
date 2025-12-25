class Solution {
public:
    
    bool canShip(vector<int>& weights, int days, int capacity) {
        int currWeight = 0;
        int requiredDays = 1;
        
        for (int w : weights) {
            if (currWeight + w > capacity) {
                requiredDays++;
                currWeight = w;
            } else {
                currWeight += w;
            }
        }
        
        return requiredDays <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        
        for (int w : weights) {
            high += w;
        }
        
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
