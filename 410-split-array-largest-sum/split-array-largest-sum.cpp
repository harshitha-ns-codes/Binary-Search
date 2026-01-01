class Solution {
public:



// Function to count number of students required
int cntSt(vector<int> &arr, int pages)
{
    int students = 1;
    long long sumOfPages = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sumOfPages + arr[i] <= pages)
        {
            sumOfPages += arr[i];
        }
        else
        {
            students++;
            sumOfPages = arr[i];
        }
    }
    return students;
}

// Main function to find minimum pages
int allocateBooks(vector<int> &arr, int n, int m)
{
    // If students > books
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int students = cntSt(arr, mid);

        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}


    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        return allocateBooks(nums,n,k);
        
    }
};