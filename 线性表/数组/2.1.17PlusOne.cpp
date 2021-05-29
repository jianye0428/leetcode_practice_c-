#include <iostream>
#include <cmath>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

class Solution1{
    public:
        vector<int> plusOne(vector<int>& digits,int digit){
            add(digits,1);
            return digits;
        }
    private:
        void add(vector<int>& digits, int digit){
            int c = digit; //carry
            for(auto it = digits.rbegin(); it != digits.rend(); ++it){
                *it += c;
                c = *it / 10;
                *it %= 10;
            }
            if(c>0){
                digits.insert(digits.begin(), 1);
            }
        }
};

class Solution2{
    public:
        vector<int> plusOne(vector<int>& digits, int digit){
            add(digits,1);
            return digits;
        }
    private:
        void add(vector<int>& digits, int digit){
            int c = digit;//carry 
            for_each(digits.rbegin(),digits.rend(), [&c](int &d){
                d += c;
                c = d / 10;
                d %= 10;
            });
            if(c>0){
                digits.insert(digits.begin(),1);
            }
        }

};

int main(){
    vector<int> digits1 = {1,2,3,4};
    vector<int> digits2 = {9,9,9,9};
    Solution1 solver1;
    Solution2 solver2;
    solver1.plusOne(digits1,1);
    solver2.plusOne(digits2,1);
    int res1=0;
    for(int i=0;i<digits1.size();++i){
        res1 = res1*10 + digits1[i];
    }
    cout << res1 << endl;
    int res2=0;
    for(int i=0;i<digits2.size();++i){
        res2 = res2*10 + digits2[i];
    }
    cout << res2 << endl;
    return 0;
}
