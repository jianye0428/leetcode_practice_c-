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

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(),nums.end());
        const int target = 0;

        auto last = nums.end();
        for(auto i = nums.begin();i < last-2; ++i){
            auto j = i + 1;
            if(i > nums.begin() && *i == *(i-1)) continue;
            auto k = last - 1;
            while(j < k){
                if(*i + *j + *k < target){
                    ++j;
                    while(*j == *(j-1) && j < k) ++j;
                }else if(*i + *(j-1) + *k > target){
                    --k;
                    while(*k == *(k+1) && j < k) --k;
                }else{
                    result.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while(*j == *(j-1) && *k == *(k + 1) && j < k) ++j;
                }
            }
        }
        return result;
    }
private:

};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solver;
    vector<vector<int>> res = solver.threeSum(nums);
    for(auto i=0; i<res.size();++i){
        for(auto j=0; j<res[0].size();++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}
