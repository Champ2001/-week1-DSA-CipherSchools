#include<bits/stdc++.h>
using namespace std;

vector<int>plusOne(vector<int> &digits){
    int n = digits.size();
    int carry = 1;

    for(int i= n-1;i>=0;i--){
        digits[i] += carry;
        carry = digits[i]/10;
        digits[i] %= 10;

        if(carry == 0){
            break;
        }

    }

    if(carry > 0){
        digits.insert(digits.begin(),carry);
    }
    return digits;
}

int main(){
    vector<int>digits= {9};
    vector<int> result = plusOne(digits);

    cout<<"The result after adding one in the number : ";
    for(int digit : result){
        cout<<digit<< " ";
    }
    cout<<endl;
}