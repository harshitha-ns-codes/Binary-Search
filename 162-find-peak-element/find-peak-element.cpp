class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 2;  // search only in the middle part

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // mid is a peak
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            }

            // if ascending at mid, peak is on right side
            if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            } else { 
                // otherwise peak is on left side
                high = mid - 1;
            }
        }

        return -1; // theoretically never reached
    }
};