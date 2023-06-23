#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid =low+(high - low)/2;
        
        if(arr[mid] == target){
            return mid;
        }
        //check if left half is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else //means right half is sorted
        if(arr[mid] <= target && target <= arr[high]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

vector<vector<int>> triplet_brute_force(vector<int>& nums){
    int n = nums.size();
    set<vector<int>>st;
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int>temp;
                    temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> triplet_better_using_hashing(vector<int>& nums){
    int n = nums.size();
    set<vector<int>>st;

    for(int i =0;i<n;i++){
        set<int>hash_set;
        for(int j = i+1;j<n;j++){
            int third = -(nums[i] + nums[j]);
            if(hash_set.find(third) != hash_set.end()){
                vector<int>temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash_set.insert(nums[j]);
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    return ans;
}

