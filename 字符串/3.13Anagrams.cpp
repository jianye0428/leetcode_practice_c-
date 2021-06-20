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
    vector<string> anagrams(vector<string>& strs){
        unordered_map<string, vector<string>> group;
        for(const auto &s:strs){
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        vector<string> result;
        for(auto it = group.cbegin(); it != group.cend(); it++){
            if(it->second.size()>1){
                result.insert(result.end(), it->second.begin(), it->second.end());
            }
        }
        return result;
    }
    
};

int main()
{

    return 0;
}
