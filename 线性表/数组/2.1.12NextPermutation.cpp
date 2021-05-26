#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
    template <typename BidiIt>
    bool next_permutation(BidiIt first, BidiIt last)
    {
        //Get a reversed range to simplify reversed traversal
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);

        //Begin from the second last element to the first element
        auto pivot = next(rfirst);

        //Find 'pivot', which is the first element that is no less than its successor, 'Prev' is
        //used since 'pivort' is a 'reversed_iterator'

        while (pivot != rlast && *pivot >= *prev(pivot))
        {
            ++pivot;
        }

        //No such element found, current sequence is already the largest
        //permutation, then rearrange to the first permutation and return false
        if (pivot == rlast)
        {
            reverse(rfirst, rlast);
            return false;
        }

        //Scan from right to left, find the first element that is greater than 'pivot'
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

        swap(*change, *pivot);
        reverse(rfirst, pivot);

        return true;
    }
};

int main()
{
    vector<int> nums = {6, 8, 7, 4, 3, 2};
    Solution solver;
    solver.nextPermutation(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
