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
    int candy(vector<int>& ratings){
        const int n = ratings.size();
        vector<int> increment(n);

        //左右各扫描一遍
        for(int i=1, inc = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                increment[i] = max(inc++, increment[i]);
            }else{
                inc = 1;
            }
        }

        for(int i = n-2, inc = 1; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                increment[i] = max(inc++, increment[i]);
            }else{
                inc = 1;
            }
        }
        //初始值为n， 因为每个小朋友至少一颗糖
        return accumulate(&increment[0],&increment[0]+n,n);
    }
};

class Solution2{
public:
    int candy(vector<int>& ratings){
        vector<int> f(ratings.size());
        int sum = 0;
        for(int i=0; i < ratings.size(); ++i){
            sum += solve(ratings, f, i);
        }
        return sum;  
    }
    int solve(const vector<int>& ratings, vector<int>& f, int i){
        if(f[i]==0){
            f[i] = 1;
            if(i > 0 && ratings[i] > ratings[i - 1]){
                f[i] = max(f[i], solve(ratings, f, i - 1)+1);
            }
            if(i < ratings.size() -1 && ratings[i] > ratings[i+1]){
                f[i] = max(f[i], solve(ratings, f, i+1)+1);
            }
        }
        return f[i];
    }
};

int main()
{
    vector<int> ratings = {0,1,2,3,2,5};
    Solution1 solver1;
    cout << solver1.candy(ratings) << endl;

    Solution2 solver2;
    cout << solver2.candy(ratings) << endl;
    return 0;
}
