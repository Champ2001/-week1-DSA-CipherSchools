#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(string &strSoFar, vector<string> &result, int open, int close)
{
    // Base case
    if (open < 0 || close < 0 || open > close)
    {
        // unbalanced
        return;
    }

    else if (open == 0 && close == 0)
    {
        result.push_back(strSoFar);
        return;
    }
    else if (open <= close)
    {
        // For adding opening brackets
        strSoFar.push_back('(');
        generateParenthesis(strSoFar, result, open - 1, close);
        strSoFar.pop_back(); // backtracking phase

        strSoFar.push_back(')');
        generateParenthesis(strSoFar, result, open, close - 1);
        strSoFar.pop_back(); // backtracking phase
    }
}

vector<string> generateParenthesis(const int n)
{
    string strSoFar = "";
    vector<string> result;
    int open = n, close = n;

    generateParenthesis(strSoFar, result, open, close);
}

//! Phone number problem 
void solve(string &digits, string mapping[] , vector<string>& ans, int index, string &output){
        if(index >= digits.size()){
            ans.push_back(output);
            return ;
        }

        int number = digits[index]-'0';
        string value = mapping[number];

        for(int i = 0 ;i<value.size();i++){
            output.push_back(value[i]);
            solve(digits, mapping, ans, index+1, output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        int index = 0;
        if(digits.size() == 0){
            return ans;
        }
        string mapping[] = {"", "" , "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        solve(digits,mapping , ans, index, output);
        return ans;
    }

//! Permutations 
void solve(int index, vector<vector<int>>&ans, vector<int>& nums){
        //Base case 
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index;i< nums.size();i++){
            swap(nums[index], nums[i]);
            solve(index+1, ans, nums);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int>>ans;

        if(nums.size() == 0){
            return ans;
        }
        solve(index, ans, nums);
        return ans;
    }