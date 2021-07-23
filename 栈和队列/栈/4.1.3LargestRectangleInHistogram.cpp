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

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    int largestRectangleArea(vector<int>& height){
        stack<int> s;
        height.push_back(0);
        int result = 0;
        for(int i=0; i< height.size();){
            if(s.empty() || height[i] > height[s.top()]){
                s.push(i++);
            }else{
                int tmp = s.top();
                s.pop();
                result = max(result, height[tmp]*(s.empty()?i:i-s.top()-1));
            }
        }
        return result;
    }
private:
    
};

int main()
{
    Solution solver;
    vector<int> vec = {2,1,5,6,2,3};
    cout <<solver.largestRectangleArea(vec) << endl;
    return 0;
}
