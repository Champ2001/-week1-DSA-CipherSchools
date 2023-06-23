#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& heights) {
    int n = heights.size();

    vector<int>lmax(n);
    vector<int>rmax(n);
    lmax[0]= heights[0];
    rmax[n-1]=heights[n-1];

    for(int i = 1;i<n;i++){
        lmax[i] = max(heights[i], lmax[i-1]);
        rmax[n-i-1] = max(heights[n-i-1], rmax[n-i]);
    }

    
    int maxWater = 0;
    for(int i = 1;i<n;i++){
        maxWater += min(lmax[i], rmax[i]) - heights[i];
    }
    return maxWater;
    }

int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};

    int trappedWater = trap(heights);

    cout << "Trapped Water: " << trappedWater << endl;
}