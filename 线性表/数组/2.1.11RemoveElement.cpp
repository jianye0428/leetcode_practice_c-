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
    int removeElement(vector<int>& nums, int target){
        int index = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != target){
                nums[index++] = nums[i];
            }
        }
        return index;
    } 
};
class Solution2{
public:
    int removeElement(vector<int>& nums, int target){
        int index = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != target){
                index++;
            }
        }
        return index;
    } 
};

class Solution3{
public:
    int removeElement(vector<int>& nums, int target){
        return distance(nums.begin(),remove(nums.begin(),nums.end(),target));
    } 
};

int main()
{
    vector<int> nums1 = {3, 2, 2, 3};
    vector<int> nums2 = {3, 2, 2, 3};
    vector<int> nums3 = {3, 2, 2, 3};
    int target = 3;
    Solution1 solver1;
    Solution2 solver2;
    Solution3 solver3;

    cout << solver1.removeElement(nums1,target) << endl;
    cout << solver2.removeElement(nums2,target) << endl;
    cout << solver3.removeElement(nums3,target) << endl;
    return 0;
}
