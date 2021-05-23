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
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> map;
        vector<int> res;
        for(int i=0; i<nums.size();++i){
            map[nums[i]] = i;
        }
        for(int i=0; i<nums.size();++i){
            const int diff = target- nums[i];
            if(map.find(diff)!=map.end()){
                res.push_back(i+1);
                res.push_back(map[diff]+1);
                break;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {2,7,11,15};
    int target = 9;
    Solution solver;
    vector<int> toPrint = solver.twoSum(v,target);
    for(int i:toPrint){
        cout << i << endl;
    }
    return 0;
}
