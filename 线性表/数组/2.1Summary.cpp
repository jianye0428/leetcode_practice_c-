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

int main()
{   
    vector<int> nums = {1,2,3,4,4,4,4,5,6,7};
    cout << nums.empty() << endl;//tell if empty
    cout << nums.size() << endl;

    cout << 0x1 << endl;//16进制的1
    cout <<"第一个迭代器的元素: "<<*nums.begin() << endl;//interator first element
    cout << "最后一个迭代器的元素: "<< *nums.end() <<endl;//interator last element   
    cout << "vector中最后一个元素: "<< *(nums.end()-1) << endl; 

    sort(nums.begin(),nums.end());
    cout << "正序排列: ";
    for(auto i:nums){
        cout << i << " ";
    }
    cout << endl;
    
    sort(nums.rbegin(),nums.rend());
    cout << "逆序排列: ";
    for(auto i:nums){
        cout << i << " ";
    }
    cout << endl;
    auto a = nums.begin();
    auto b = nums.end();
    cout << *prev(b) << endl;
    cout << *next(a) << endl;
    cout << *next(a,2) << endl;
    cout << *prev(b,2) << endl;

    vector<int> nums2 = {1,2,3,4,4,4,4,5,6,7};
    cout << *upper_bound(nums2.begin(),nums2.end(),4) << endl;
    cout << *lower_bound(nums2.begin(),nums2.end(),4) << endl;
    cout << distance(nums.begin(),remove(nums.begin(),nums.end(),4)) << endl;


    auto c = reverse_iterator<vector<int>::iterator>(nums2.end());
    auto d = reverse_iterator<vector<int>::iterator>(nums2.begin());
    cout << "c = " << *c << " and d = " << *d << endl;
    cout << "next(c) = " << *next(c) << " and prev(d) = " << *prev(d) << endl;

    cout << accumulate(nums.begin(), nums.end(), 0) << endl;
    return 0;
}
