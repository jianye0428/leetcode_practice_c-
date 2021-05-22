/*Remove Duplicates from Sorted Array*/
#include<iostream>
#include<vector>
using namespace std;
class Solution1{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int index = 0;
        for(int i=1; i<nums.size(); ++i){
            if(nums[index]!=nums[i])
                nums[++index]=nums[i];
        }
        return index+1;
    }
};

int main(){
    vector<int> a{1,1,2};
    Solution1 fix;
    int ans;
    ans = fix.removeDuplicates(a);
    cout << ans << endl;
    return 0;
    
}
