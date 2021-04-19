#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int searchInRotatedArrayI(const vector<int>& nums, int target){
        int first = 0, last = nums.size();
        while(first!=last){
            const int mid = first +(last-first)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[first]<=nums[mid]){
                if(nums[first] <= target && target <nums[mid]){
                    last = mid;
                }else{
                    first = mid+1;
                }
            }else{
                if(nums[mid]<target && target <=nums[last-1]){
                    first = mid+1;
                }else{
                    last = mid;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> v{4,5,6,7,0,1,2};

    int target = 6;

    Solution solver;


    cout << solver.searchInRotatedArrayI(v,target) << endl;
    return 0;
}