#include<bits/stdc++.h>
using namespace std;

 vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left =0 , top = 0, right = m-1, bottom = n-1;

        int direction = 1;
        vector<int>v;
        while(left <= right && top <= bottom){
            if(direction == 1){
                direction = 2;
                for(int i=left;i<= right;i++){
                    v.push_back(matrix[top][i]);
                }
                    top++;
                
            }
            else if(direction == 2){
                direction = 3;
                for(int i= top; i<= bottom ;i++){
                    v.push_back(matrix[i][right]);
                }
                    right--;
                
            }
            else if(direction == 3){
                direction = 4;
                for(int i= right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                    bottom--;
                
            }
            else if(direction == 4){
                direction = 1;
                for(int i=bottom;i>= top;i--){
                    v.push_back(matrix[i][left]);
                }
                    left++;
                
            }
        }
        return v;
    }
    int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}