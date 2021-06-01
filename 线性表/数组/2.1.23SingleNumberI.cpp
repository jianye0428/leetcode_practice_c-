#include<iostream>
#include<cmath>
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
    int singleNumber(vector<int>& nums){
        int x = 0;
        for(auto i:nums){
            x = x ^ i;
        }
        return x;
    }
};

class Solution2{
    public:
        int singleNumber(vector<int>& nums){
            return accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        }
};

int main()
{
    vector<int> nums = {1,2,1,2,11,11,5,6,8,7,7,6,8};
    Solution1 solver1;
    Solution2 solver2;     
    cout << solver1.singleNumber(nums) << endl;
    cout << solver2.singleNumber(nums) << endl;
    return 0;
}
