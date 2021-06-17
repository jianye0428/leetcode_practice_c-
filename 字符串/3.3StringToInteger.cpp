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
    int myAtoi(const string& str){
        int num = 0;
        int sign = 1;
        const int n = str.length();
        int i = 0;

        while(str[i] == ' ' && i < n){
            i++;
        }
        if(str[i] == '+'){
            i++;
        }else if(str[i] == '-'){
            sign = -1;
            i++;
        }

        for(;i<n;i++){
            if(str[i] < '0' || str[i] >'9'){
                break;
            }
            if(num > INT_MAX/10 || (num == INT_MAX / 10 && (str[i]-'0')> INT_MIN%10)){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            num = num * 10 + str[i] - '0';
        }
        return num*sign;
    }    
};

int main()
{

    string s = "   -89898910";
    Solution solver;
    cout << solver.myAtoi(s) << endl;
    return 0;
}
