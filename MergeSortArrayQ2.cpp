#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int target)
{
    int size = nums.size();
    int start = 0;
    int last = size - 1;
    int index = -1;
    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        if (nums[mid] == target)
        {
            index = mid;
            last = mid - 1;
        }
        else if (nums[mid] > target)
        {
            last = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return index;
}

int lastOccurence(vector<int> &nums, int target)
{
    int size = nums.size();
    int start = 0;
    int last = size - 1;
    int index = -1;
    while (start <= last)
    {
        int mid = start + (last - start) / 2;
        if (nums[mid] == target)
        {
            index = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
        {
            last = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return index;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int firstOcc = firstOccurence(nums, target);
    int secondOcc = lastOccurence(nums, target);
    return {firstOcc, secondOcc};
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5, 6};
    int target = 4;

    vector<int> result = searchRange(nums, target);

    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}