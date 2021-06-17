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

typedef string::const_iterator Iterator;
namespace std{
    template<>
    struct hash<pair<Iterator, Iterator>>{
        size_t operator()(pair<Iterator, Iterator> const& p){
            return ((size_t) &(*p.first))^((size_t) &(*p.second));
        }
    };
}

class Solution1{
public:
    string longestPalindrome(string const& s){
        cache.clear();
        return cachedLongestPalindrome(s.begin(), s.end());
    }
private:
    unordered_map<pair<Iterator, Iterator>, string> cache;

    string longestPalindrome(Iterator first, Iterator last){
        size_t length = distance(first, last);

        if(length < 2) {
            return string(first, last);
        }

        auto s = cachedLongestPalindrome(next(first), prev(last));

        if(s.length() == length - 2 && *first == *prev(last)) {
            return string(first, last);
        }

        auto s1 = cachedLongestPalindrome(next(first), last);
        auto s2 = cachedLongestPalindrome(first, prev(last));

        if(s.size() > s1.size()){
            return s.size() > s2.size() ? s:s2;
        }else{
            return s1.size() > s2.size() ? s1:s2;
        }
    }

    string cachedLongestPalindrome(Iterator first, Iterator last){
        auto key = make_pair(first, last);
        auto pos = cache.find(key);

        if(pos != cache.end()){
            return pos->second;
        }else{
            return cache[key] = longestPalindrome(first, last);
        }
    }
    
};


class Solution2{
public:
    string longestPalindrome(const string& s){
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n*n, false);

        size_t max_len = 1, start = 0;

        for(size_t i = 0; i <s.size(); i++){
            f[i][i] = true;
            for(size_t j = 0; j<i; j++){
                f[j][i] = (s[j] == s[i] && (i - j - 2 || f[j+1][i-1]));
                if(f[j][i] && max_len < (i - j + 1)){
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

//Manacher's Algo
class Solution3{
public:
    //Transform S into T
    //For example S = "abba", T = "^#a#b#b#a#$"
    string preProcess(const string& s){
        int n = s.length();
        if(n == 0) {
            return "^$";
        }
        string ret = "^";
        for(int i=0; i<n; i++){
            ret += "#" + s.substr(i,1);
        }
        ret += "$";
        return ret;
    }
    string longestPalindrome(string s){
        string T = preProcess(s);
        const int n = T.length();

        int P[n];
        int C=0, R=0;

        for(int i=1; i<n-1; i++){
            int i_mirror = 2*C-i; //equal to i' = C - (i - C)
            P[i] = (R > i) ? min(R - i, P[i_mirror]) :0;

            while(T[i+1+P[i]] == T[i - 1 - P[i]]){
                P[i]++;
            }

            if(i+P[i] > R){
                C = i;
                R = i + P[i];
            }

            

        }
        int max_len = 0;
        int center_index = 0;
        for(int i=1; i< n-1; i++){
            if(P[i] > max_len){
                max_len = P[i];
                center_index = i;
            }
        }
        return s.substr((center_index-1-max_len)/2, max_len);
    }
};
int main()
{
    return 0;
}
