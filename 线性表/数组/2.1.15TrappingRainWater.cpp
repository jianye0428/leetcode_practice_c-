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
    int trap(const vector<int>& A){
        const int n = A.size();
        int* max_left = new int[n]();
        int* max_right = new int[n]();

        for(int i = 1; i < n; i++){
            max_left[i] = max(max_left[i-1],A[i-1]);
            max_right[n - 1 -i] = max(max_right[n-i], A[n-i]);
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            int height = min(max_left[i], max_right[i]);
            if(height > A[i]){
                sum += height - A[i];
            }
        }

        delete[] max_left;
        delete[] max_right;
        return sum;
    }  
};

class Solution2{
public:
    int trap(const vector<int>& A){
        const int n = A.size();
        int max = 0;
        for(int i = 0; i < n; i++){
            if(A[i] > A[max]){
                max = i;
            }
        }

        int water = 0;
        for(int i = 0, peak = 0; i < max; i++){
            if(A[i] > peak){
                peak = A[i];
            }else{
                water += peak - A[i];
            }
        }
        for(int i = n - 1, top = 0; i > max; i--){
            if(A[i] > top){
                top = A[i];
            }else{
                water += top - A[i];
            }
        }
        return water;
    }  
};

class Solution3{
public:
    int trap(const vector<int>& A){
        const int n = A.size();
        stack<pair<int, int>> s;
        int water = 0;

        for(int i = 0; i < n; ++i){
            int height = 0;
            while(!s.empty()){//将栈里比当前元素矮或等高的元素全部处理掉
                int bar = s.top().first;
                int pos = s.top().second;
                // bar, height, A[i] 三者夹成的凹陷
                water += (min(bar, A[i]) - height) * (i - pos - 1);
                height = bar;

                if(A[i] < bar){ //碰到了比当前元素高的，跳出循环
                    break;
                }else{
                    s.pop();//弹出栈顶，因为该元素处理完了，不在需要了
                }
            }
            s.push(make_pair(A[i], i));
        }
        return water;
    }  
};

int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution1 solver1;
    Solution2 solver2;
    Solution3 solver3;
    cout << solver1.trap(nums) << endl;
    cout << solver2.trap(nums) << endl;
    cout << solver3.trap(nums) << endl;
    return 0;
}
