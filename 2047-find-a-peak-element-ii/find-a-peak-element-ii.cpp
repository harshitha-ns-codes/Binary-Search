class Solution {
public:

    int findMax(vector<vector<int>>& mat, int m, int col)
    {
        int maxValue = -1;
        int index = -1;

        for(int i = 0; i < m; i++)
        {
            if(mat[i][col] > maxValue)
            {
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            int row = findMax(mat, m, mid);

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < n) ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right)
            {
                return {row, mid};
            }
            else if(left > mat[row][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};