#include <iostream>
#include <cmath>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

class Solution1{
public:
    void rotate(vector<vector<int>>& matrix){
        const int n = matrix.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n-1; ++j){
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        for(int i=0; i<n / 2; ++i){
            for(int j=0; j<n; j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
    }
};


class Solution2{
public:
    void rotate(vector<vector<int>>& matrix){
        const int n = matrix.size();
        for(int i=0; i<n / 2; ++i){
            for(int j=0; j<n; j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> nums1 = {{1,2},{3,4}};
    vector<vector<int>> nums2 = {{1,2},{3,4}};
    Solution1 solver1;
    Solution2 solver2;
    solver1.rotate(nums1);
    solver2.rotate(nums2);

    for(int i = 0; i < nums1.size();++i){
        for(int j=0; j < nums1.size();++j){
            cout << nums1[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < nums2.size();++i){
        for(int j=0; j < nums2[0].size();++j){
            cout << nums1[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
