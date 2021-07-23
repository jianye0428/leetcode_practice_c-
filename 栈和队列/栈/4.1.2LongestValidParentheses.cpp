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

class Solution1{
public:
    int longestValidParentheses(const string& s){
        int max_len = 0, last = -1;
        stack<int> lefts;

        for(int i=0; i < s.size(); ++i){
            if(s[i] == '('){
                lefts.push(i);
            }else{
                if(lefts.empty()){
                    last = i;
                }else{
                    lefts.pop();
                    if(lefts.empty()){
                        max_len = max(max_len, i-last);
                    }else{
                        max_len = max(max_len, i-lefts.top());
                        // cout << lefts.top() << endl;
                    }
                }
            }
        }
        return max_len;
    }
};

class Solution2{
public:
        int longestValidParentheses(const string& s){
            vector<int> f(f.size(), 0);
            int ret = 0;
            for(int i = s.size()-2; i >= 0; --i){
                int match = i + f[i+1] + 1;
                if(s[i] == '(' && match < s.size() && s[match] == ')'){
                    f[i] = f[i+1] +2;
                    // if a valid sequence exist afterwards "((...))()"
                    if(match + 1 < s.size()){
                        f[i] += f[match + 1];
                    }
                }
                ret = max(ret, f[i]);
            }
            return ret;
        }
};

class Solution3{
public:
    int longestValidParentheses(const string& s){
        int answer = 0, depth = 0, start = -1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                ++depth;
            }else{
                --depth;
                if(depth < 0){
                    start = i;
                    depth = 0;
                }else if(depth == 0){
                    answer = max(answer, i - start);
                }
            }
        }
        depth = 0;
        start = s.size();
        for(int i = s.size()-1; i >=0; --i){
            if(s[i] == ')'){
                ++depth;
            }else{
                --depth;
                if(depth < 0){
                    start = i;
                    depth = 0;
                }else if(depth == 0){
                    answer = max(answer, start - 1);
                }
            }
        }
        return answer;
    }
};


int main()
{
    string s1 = "(()()";
    Solution1 solver1;
    cout << solver1.longestValidParentheses(s1) << endl;
    string s2="(()()";
    Solution2 solver2;
    cout << solver2.longestValidParentheses(s2) << endl;
    string s3 = "(()()";
    Solution3 solver3;
    cout << solver3.longestValidParentheses(s3) << endl;
    return 0;
}
