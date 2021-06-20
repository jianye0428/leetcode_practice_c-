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
//STL
class Solution1{
public:
    int lengthOfLastWord(const string& s){
        auto first =  find_if(s.rbegin(),s.rend(),::isalpha);
        auto last  =  find_if_not(first,s.rend(),::isalpha);

        return distance(first,last);
    }
    
};
//顺序扫描
class Solution2{
public:
    int lengthOfLastWord(const string& s){
        return lengthOfLastWord(s.c_str());
    }
private:
    int lengthOfLastWord(const char *s){
        int len = 0;
        while(*s){
            if(*s++ != ' '){
                ++len;
            }else if(*s && *s != ' '){
                len = 0;
            }
        }
        return len;
    }
    
};

int main()
{
    return 0;
}
