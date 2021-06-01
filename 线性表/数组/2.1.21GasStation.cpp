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

class Solution{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int total = 0;
        int j = -1;
        for(int i=0, sum = 0; i < gas.size(); ++i){
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0){
                j = i;
                sum = 0;  
            }
        }
        return total >= 0 ? j+1 : -1;
    }
};

int main()
{
    vector<int> gas = {1,0,2,4,1,2};
    vector<int> cost = {1,1,2,3,2,1};
    Solution solver;
    cout << solver.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
