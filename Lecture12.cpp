#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& b, string w) 
    {
        int m=b.size(),n=b[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(b[i][j]==w[0])       
                    if(find(b,w,i,j,0))            return true;
        return false;    
    }
    bool find(vector<vector<char>> &b, string w, int i, int j, int x)
    {
        if(x==w.size())        return true;
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size())   return false;
        if(b[i][j]!=w[x] || b[i][j]=='-1')      return false;
        else{
            b[i][j]='-1';
            if(find(b,w,i+1,j,x+1) || find(b,w,i,j+1,x+1) || find(b,w,i-1,j,x+1) || find(b,w,i,j-1,x+1))            return true;;
            b[i][j]=w[x];
            return false;
        }

    }
};

vector<vector<int>> power(vector<int>& nums){
        vector<vector<int>> TotalSubsets;
        int n=nums.size();
        for(int num=0;num<=pow(2,n)-1;num++){
            vector<int> sub;
            for(int i=0;i<=n-1;i++){
                if(num&(1<<i)){
                    sub.push_back(nums[i]);
                }
            }
            TotalSubsets.push_back(sub);
        }
        return TotalSubsets;
    }

     double myPow(double x, int n) {
        if(n==0)return 1;
        if(n==1)return x;
        if(n>0){
        if(n%2==0)return myPow(x*x,n/2);
        else return x*myPow(x*x,n/2);
        }
        else{
            n=abs(n);
            if(n%2==0)return 1/(myPow(x*x,n/2));
        else return 1/(x*myPow(x*x,n/2));
       
        }
        
    }