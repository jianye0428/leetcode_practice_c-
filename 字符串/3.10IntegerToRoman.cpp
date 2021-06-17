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
    string intToRoman(int num){
        const int radix[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        const string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string roman;

        for(size_t i = 0; num > 0; i++){
            int count = num/radix[i];
            num %= radix[i];
            for(;count > 0; --count){
                roman += symbol[i];
            }
        }
        return roman;
    }
    


    
};

int main()
{
    return 0;
}
