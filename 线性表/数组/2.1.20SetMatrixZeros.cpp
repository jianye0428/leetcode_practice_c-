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
    void setMatrixZeros(vector<vector<int>>& matrix){
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(size_t i =0; i < m; ++i){
            for(size_t j = 0; j<n; ++j){
                if(matrix[i][j] == 0){
                    row[i] = col[j] = true;
                }
            }
        }

        for(size_t i=0; i<m; ++i){
            if(row[i]){
                fill(&matrix[i][0], &matrix[i][0]+n, 0);
            }
        }
        for(size_t j = 0; j<n; ++j){
            if(col[j]){
                for(size_t i=0; i<m; ++i){
                    matrix[i][j] = 0;
                }
            }

        }

    }    
};


class Solution2{
public:
    void setMatrixZeros(vector<vector<int>>& matrix){
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();

        bool row_has_zero = false;
        bool col_has_zero = false;

        for(size_t i=0; i<n; i++){
            if(matrix[0][i] == 0){
                row_has_zero = true;
                break;
            }
        }

        for(size_t i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                col_has_zero = true;
                break;
            }
        }

        for(size_t i=1; i<m; i++){
            for(size_t j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(size_t i=1; i < m; i++){
            for(size_t j=1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(row_has_zero){
            for(size_t i=0; i< n; ++i){
                matrix[0][i] = 0;
            }
        }
        if(col_has_zero){
            for(size_t j=0; j< m; ++j){
                matrix[j][0] = 0;
            }
        }
    }    
};
int main()
{
    vector<vector<int>> matrix1{{1,1,0,1},{1,1,1,1},{0,1,1,1},{1,0,1,1}};
    vector<vector<int>> matrix2{{1,1,0,1},{1,1,1,1},{0,1,1,1},{1,0,1,1}};
    Solution1 solver1;
    Solution2 solver2;
    solver1.setMatrixZeros(matrix1);
    solver2.setMatrixZeros(matrix2);

    for(int i=0; i < matrix1.size(); ++i){
        for(int j=0; j < matrix1[0].size(); ++j){
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0; i < matrix2.size(); ++i){
        for(int j=0; j < matrix2[0].size(); ++j){
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
