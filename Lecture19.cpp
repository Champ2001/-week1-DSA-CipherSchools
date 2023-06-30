#include<bits/stdc++.h>
using namespace std;

//!Merge Intervals

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[i] , intervals[i][1]);
            }
        }
        return ans;
    }

    //!Top k frequent elements
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto it: mp){
            pq.push(make_pair(it.second, it.first));
            while(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }