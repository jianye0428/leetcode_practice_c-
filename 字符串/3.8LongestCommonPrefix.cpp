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
    string longestCommonPrefix(vector<string> &str){
        if(str.empty()) return "";

        for(int idx = 0; idx < str[0].size(); ++idx){
            for(int i = 1; i < str.size(); ++i){
                if(str[i][idx] != str[0][idx]){
                    return str[0].substr(0,idx);
                }
            }
        }
        return str[0];
    }
    
};

class Solution2{
public:
    string longestCommonPrefix(vector<string> &str){
        if(str.empty()) return "";

        int right_most = str[0].size() - 1;
        for(size_t i = 1; i < str.size(); i++){
            for(int j = 0; i <= right_most; j++){
                if(str[i][j] != str[0][j]){
                    right_most = j - 1;
                }
            }
        }
        return str[0].substr(0, right_most+1);
    }
    
};

int main()
{
    return 0;
}
