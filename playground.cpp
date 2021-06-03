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


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

int main()
{
    // vector<int> v = {1,2,3,4};
    // cout << *(v.end()-1)<< endl;
    // bool used[9];
    // cout << used[0] << endl;
    // cout << used[1] << endl;
    const size_t s = 1<<6;
    cout << s << endl;
    int inc = 1;
    int a = inc++;
    cout << a << endl;
    cout << inc << endl;

    cout << sizeof(int) * 8 << endl;

    return 0;
}
