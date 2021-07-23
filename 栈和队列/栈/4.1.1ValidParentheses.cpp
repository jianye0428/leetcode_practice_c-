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
    bool isValid(string const& s){
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for(auto c:s){
            if(left.find(c) != string::npos){
                stk.push(c);
            }else{
                if(stk.empty() || stk.top() != left[right.find(c)]){
                    return false;
                }else{
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
    
};

int main()
{
    string s = "}{";
    Solution solver;
    cout << solver.isValid(s) << endl;
    return 0;
}
