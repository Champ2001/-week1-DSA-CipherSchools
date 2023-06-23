#include<bits/stdc++.h>
using namespace std;

int lenghtOfWord(string &str){
    int length =0;
    int n = str.length() -1;
    for(int i = n-1; i>= 0;i--){
        if(str[i] != ' '){
            length++;
        }
        else if (length > 0){
            break;
        }
    }
    return length;
}
int main(){
    string str = "   fly me   to   the moon  ";
    int lengths = lenghtOfWord(str);
    cout<<"Length of last word is " << lengths;
}