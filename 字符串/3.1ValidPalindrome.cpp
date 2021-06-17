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
    bool isPalindrome(string s){
        transform(s.begin(), s.end(), s.begin(),::tolower);

        auto left = s.begin(), right = prev(s.end());
        while(left < right){
            if(!::isalnum(*left)){
                ++left;
            }else if(!::isalnum(*right)){
                --right;
            }else{
                ++left;
                --right;
            }
        }
        return true;
    }    

    
};

int main()
{
    string s = "A man, a plan, a canal: Panama";

    Solution solver;
    cout << solver.isPalindrome(s) << endl;
    return 0;
}
