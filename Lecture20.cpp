#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerIndex(vector<int>&arr, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            int cur=arr[i];
            while(s.top() != -1 && arr[s.top()] >= cur){
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerIndex(vector<int>&arr, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int cur=arr[i];
            while(s.top() != -1 && arr[s.top()] >= cur){
                s.pop();
            }
            //Answer is again array ka top
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev(n);
        prev=prevSmallerIndex(heights, n);
        vector<int>next(n);
        next=nextSmallerIndex(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i] == -1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
};