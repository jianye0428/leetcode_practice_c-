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
    inline int map(const char c){
        switch(c){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default  : return 0;
        }
    }

    int romanToInt(const string& s){
        int result = 0;
        for(size_t i=0; i<s.size(); ++i){
            if(i>0 && map(s[i])>map(s[i-1])){
                result += (map(s[i]) - 2 * map(s[i-1]));
            }else{
                result += (map(s[i]));
            }
        }
        return result;
    }
    
};

int main()
{
    return 0;
}
