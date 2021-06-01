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
        const int W = sizeof(int) * 8; //一个整数的bit数，整数字长
        int count[W]; //count[i] 表示在i位出现的1的次数
        fill_n(&count[0], W, 0);
        for(int i = 0; i < nums.size(); ++i){
            for(int j=0; j < W; j++){
                count[j] += (nums[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        int result =0;
        for(int i=0; i < W; i++){
            result += (count[i] << i);
        }
        return result;
    }
};

class Solution2{
public:
    int singleNumber(vector<int>& nums){
        int one = 0, two = 0, three = 0;
        for(auto i : nums){
            two |= (one & i);
            one ^= i;
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};

int main()
{
    vector<int> nums = {1,2,1,3,1,2,2};
    Solution1 solver1;
    Solution2 solver2;
    cout << solver1.singleNumber(nums) <<endl;
    cout << solver2.singleNumber(nums) <<endl;
    return 0;
}
