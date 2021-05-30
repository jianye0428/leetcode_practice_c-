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

class Solution1{
public:
    int climbStairs(int n){
        int prev = 0;
        int cur = 1;
        for(int i=1; i<n; i++){
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }
        return cur;
    }    
};

class Solution2{
public:
    int climbStairs(int n){
        const double s = sqrt(5);
        return floor((pow((1+s)/2, n) - pow((1-s)/2, n))/s + 0.5);
    }    
};

int main()
{
    Solution1 solver1;
    Solution2 solver2;
    cout << solver1.climbStairs(10) << endl;
    cout << solver2.climbStairs(10) << endl;
    return 0;
}
