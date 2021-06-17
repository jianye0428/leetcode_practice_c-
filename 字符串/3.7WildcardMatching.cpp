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
// Recursion
class Solution1{
public:
    bool isMatch(const string& s, const string& p){
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(const char *s, const char *p){
        if(*p == '*'){
            while(*p == '*'){
                ++p;
            }
            if(*p == '\0') return true;
            while(*s != '\0' && !isMatch(s, p)){
                ++s;
            }
            return *s != '\0';
        }else if(*p =='\0' || *s == '\0'){
            return *p == *s;
        }else if(*p == *s || *p == '?'){
            return isMatch(++s, ++p);
        }else{
            return false;
        }
    }
};
//iteration
class Solution2{
public:
    bool isMatch(const string& s, const string& p){
        return isMatch(s.c_str(), p.c_str());
    }
private:
   bool isMatch(const char *s, const char *p){
       bool star = false;
       const char *str, *ptr;
       for(str = s, ptr = p; *str != '\0'; str++, ptr++){
           switch(*ptr){
               case '?':
                    break;
               case '*':
                    star = true;
                    s = str, p = ptr;
                    while(*p == '*'){
                        p++;
                    }
                    if(*p == '\0') return true;
                    str = s - 1;
                    ptr = p - 1;
                    break;
               default:
                    if(*str != *ptr){
                        if(!star){return false;}
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }    
           }
       }
       while(*ptr == '*') ptr++;
       return (*ptr == '\0');
   }
};

int main()
{
    return 0;
}
