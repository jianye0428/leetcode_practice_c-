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
    int longestConsecutive(const vector<int> &nums){
        unordered_map<int,bool> used;
        for(auto i:nums){
            used[i] = false;
        }
        int longest = 0;

        for(auto i:nums){
            if(used[i]){
                continue;
            }
            int length = 1;
            used[i] = true;
            for(int j=i+1; used.find(j)!=used.end(); ++j){
                used[j] = true;
                ++length;
            }
            for(int j=i-1; used.find(j)!=used.end(); --j){
                used[j] = true;
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
    }

};

class Solution_new{
public:
    int longestConsecutive(vector<int> &nums){
        unordered_map<int,int> map;
        int size = nums.size();
        int l=1;
        for(int i=0; i<size; ++i){
            if(map.find(nums[i])!=map.end()){
                continue;
            }
            map[nums[i]] = 1;
            if(map.find(nums[i]-1)!=map.end()){
                l = max(l, mergeCluster(map,nums[i]-1,nums[i]));
            }
            if(map.find(nums[i]+1)!=map.end()){
                l = max(l, mergeCluster(map,nums[i],nums[i+1]));
            }
        }
        return size == 0 ? 0 : l;
    }
private:
    int mergeCluster(unordered_map<int,int>& map, int left, int right){
        int upper = right + map[right] -1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    }

};

int main()
{
    vector<int> v{100,4,200,1,3,2};
    Solution solver;
    cout << solver.longestConsecutive(v) << endl;
    return 0;
}
