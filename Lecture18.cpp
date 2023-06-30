#include<bits/stdc++.h>
using namespace std;


//!Valid Parenthesis
 bool isValid(string s) {
        stack<char>st;
        for(auto it: s){
            if(it == '(' || it == '{' || it =='['){
                st.push(it);
            }
            else{
                if(st.empty())return false;
                char ch= st.top();
                st.pop();
                if((ch == '(' && it ==')')||(ch == '{' && it =='}')||(ch == '[' && it ==']')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }

//! Minimum Number of Swaps to Make the String Balanced
int minSwaps(string s) {
        string unpurified = "";
        for(int i =0;i<s.size();i++){
            if(s[i] == '['){
                unpurified.push_back('[');
            }
            else{
                if(!unpurified.empty() && unpurified.back() == '['){
                    unpurified.pop_back();
                }
                else{
                    unpurified.push_back(s[i]);
                }
            }
        }
        int open = unpurified.size()/2;
        return ((open+1)/2);
    }