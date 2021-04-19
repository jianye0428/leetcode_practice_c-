#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool searchInRotatedArrayI(const vector<int>& nums, int target){
        int first = 0, last = nums.size();
        while(first!=last){
            const int mid = first +(last-first)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[first]<nums[mid]){
                if(nums[first] <= target && target <nums[mid]){
                    last = mid;
                }else{
                    first = mid+1;
                }
            }else if(nums[first]>nums[mid]){
                if(nums[mid]<target && target <=nums[last-1]){
                    first = mid+1;
                }else{
                    last = mid;
                }
            }else{
                first++;
            }
        }
        return false;
    }
};

int main(){
    vector<int> v{1,3,1,1,1};

    int target = 1;

    Solution solver;

    cout << solver.searchInRotatedArrayI(v,target) << endl;
    return 0;
}