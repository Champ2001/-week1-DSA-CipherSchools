#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    stack<int>s;
    solve(myStack, x);
    return myStack;
}
