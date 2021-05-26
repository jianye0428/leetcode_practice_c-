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
    string getPermutation(int n, int k)
    {
        string s(n, '0');
        string result;
        for (int i = 0; i < n; i++)
        {
            s[i] += i + 1;
        }
        return kth_permutation(s, k);
    }

private:
    // 阶乘
    int factorial(int n)
    {
        int result = 1;
        for (int i = 1; i <= n; ++i)
        {
            result *= i;
        }
        return result;
    }

    // seq 已排好序 ，是第一个排列
    template <typename Sequence>
    Sequence kth_permutation(const Sequence &Seq, int k)
    {
        const int n = Seq.size();
        Sequence S(Seq);
        Sequence result;

        int base = factorial(n - 1);
        --k; // 康托编码从零开始
        for (int i = n - 1; i > 0; k %= base, base /= i, --i)
        {
            auto a = next(S.begin(), k / base);
            result.push_back(*a);
            S.erase(a);
        }

        result.push_back(S[0]); //最后一个
            return result;
    }
};

int main()
{
    int n = 4, k = 8;
    Solution solver;
    cout << solver.getPermutation(n, k) << endl;

    return 0;
}
