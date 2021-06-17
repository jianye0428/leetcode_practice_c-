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
    bool isNumber(const string& s){
        enum InputType {
            INVALID,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXPONENT,
            NUM_INPUTS
        };
        const int transitionTable[][NUM_INPUTS] = {
            -1, 0, 3, 1, 2, -1,
            -1, 8, -1, 1, 4, 5,
            -1, -1, -1, 4, -1, -1, 
            -1, -1, -1, 1, 2, -1,
            -1, -8, -1, 4, -1, 5,
            -1, -1, 6, 7, -1, -1, 
            -1, -1, -1, 7, -1, -1,
            -1, 8, -1, 7, -1, -1,
            -1, 8, -1, -1, -1, -1,
        };
        int state = 0;
        for(auto ch:s){
            InputType inputType = INVALID;
            if(isspace(ch)){
                inputType = SPACE;
            }else if(ch == '+' || ch == '-'){
                inputType = SIGN;
            }else if(isdigit(ch)){
                inputType = DIGIT;
            }else if(ch == '.'){
                inputType = DOT;
            }else if(ch == 'e' || ch == 'E'){
                inputType = EXPONENT;
            }
            state = transitionTable[state][inputType];
            if(state == -1){
                return false;
            }
        }
        return state == 1 || state == 4 || state ==7 || state == 8;
    }
};

class Solution1{
public:
    bool isNumber(const string& s){
        return isNumber(s.c_str());
    }
private:
    bool isNumber(char const* s){
        char* endptr;
        strtod(s, &endptr);

        if(endptr == s){
            return false;
        }

        for(;*endptr;++endptr){
            if(!isspace(*endptr)){
                return false;
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}
