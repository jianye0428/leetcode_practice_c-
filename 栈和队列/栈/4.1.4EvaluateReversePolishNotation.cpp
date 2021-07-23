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
    int evalRPN(vector<string>& tokens){
        int x,y;
        auto token = tokens.back();     
        tokens.pop_back();
        if(is_operator(token)){
            y = evalRPN(tokens);
            x = evalRPN(tokens);
            if(token[0]=='+')        x += y;
            else if(token[0] == '-') x -= y;
            else if(token[0] == '*') x *= y;
            else                     x /= y;
        }else{
            size_t i;
            x = stoi(token, &i);
        }
        return x;
    }
private:
    bool is_operator(const string& op){
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};

class Solution2{
public:
    int evalRPN(vector<string>& tokens){
        stack<string> s;
        for(auto token:tokens){
            if(!is_operator(token)){
                s.push(token);
            }else{
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                if(token[0] == '+')   x += y;
                else if(token[0] == '-') x -= y;
                else if(token[0] == '*') x *= y;
                else                  x /= y;
                s.push(to_string(x));   
            }
        }
        return stoi(s.top());
    }
private:
    bool is_operator(const string& op){
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }

};

int main()
{
    vector<string> vec1 = {"2","1","+","3","*"};
    Solution1 solver1;//
    cout << solver1.evalRPN(vec1) << endl;//
    vector<string> vec2 = {"2","1","+","3","*"};
    Solution2 solver2;
    cout << solver2.evalRPN(vec2) << endl;
    return 0;
}
