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
    string addBinary(string a, string b){
        string result;
        const size_t n = a.size() > b.size() ? a.size() : b.size();

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int carry = 0;
        for(size_t i = 0; i < n; i++){
            const int ai = i < a.size() ? a[i] - '0':0;
            const int bi = i < b.size() ? b[i] - '0':0;

            const int val = (ai + bi +carry) % 2;
            carry = (ai + bi +carry) / 2;

            result.insert(result.begin(), val + '0');
        }

        if(carry == 1){
            result.insert(result.begin(), '1');
        }
        return result;
    }
    
};

int main()
{

    string a = "11";
    string b = "1";
    Solution solver;

    string res;
    res = solver.addBinary(a,b);

    for(auto i:res){
        cout << i;
    }
    cout << endl;


    return 0;
}
