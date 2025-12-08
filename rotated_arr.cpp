#include <iostream>
using namespace std;

int rotated_arr()
{
    int low = 0 , high = n-1;
    while(low <= high)
    int mid = (low+high)/2;
    {
        if(arr[mid] == target) return mid;

        if(arr[low] <= target && target<= arr[mid])
        {
            high = mid -1;
        }
        else
        {
            low = mid +1;
        }

        if(arr[mid] <= target && target<= arr[high])
        {
            low = mid +1;
            high = mid -1;
        }
        else
        {
             high = mid -1;
        }


    }
}