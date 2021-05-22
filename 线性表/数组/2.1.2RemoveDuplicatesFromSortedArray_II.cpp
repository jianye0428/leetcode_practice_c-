/*Remove Duplicates from Sorted Array II*/
#include<iostream>
#include<vector>
using namespace std;
class Solution1{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        if(nums.size()<=2) return nums.size();
        int index = 2;
        for(int i=2; i<nums.size(); ++i){
            if(nums[i]!=nums[index-2])
                nums[index++]=nums[i];
        }
        return index;
    }
};

class Solution2{
public:
    int removeDuplicates(vector<int>& nums){
        const int n = nums.size();
        int index = 0;
        for(int i=0; i<n; ++i){
            if(i>0 && i<n-1 && (nums[i]==nums[i-1]) && (nums[i]==nums[i+1])){
                continue;
            }
            nums[index++]=nums[i];
        }
        return index;
    }
};

int main(){
    vector<int> a1{1,1,1,2,2,3};
    Solution1 fix1;
    int ans1;
    ans1 = fix1.removeDuplicates(a1);
    cout << ans1 << endl;

    vector<int> a2{1,1,1,2,2,3};
    Solution2 fix2;
    int ans2;
    ans2 = fix2.removeDuplicates(a2);
    cout << ans2<< endl;
    return 0;
    
}
