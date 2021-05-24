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
//左右夹逼
class Solution1{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for(auto a = nums.begin(); a<prev(nums.end(),3);++a){
            for(auto b = next(a); b<prev(last,2); ++b){
                auto c = next(b);
                auto d = prev(last);

                while(c < d){
                    if(*a + *b + *c + *d < target){
                        ++c;
                    }else if(*a + *b + *c + *d > target){
                        --d;
                    }else{
                        result.push_back({*a, *b, *c, *d});
                        ++c;
                        --d;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(),result.end()), result.end());
        return result;
    }        
};

//map做缓存
class Solution2{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> result;
        if(nums.size()<4) return result;
        sort(nums.begin(),nums.end());

        unordered_map<int, vector<pair<int,int>>> cache;
        for(size_t a = 0; a < nums.size(); ++a){
            for(size_t b = a + 1; b < nums.size(); ++b){
                cache[nums[a]+nums[b]].push_back(pair<int,int>(a,b));
            }
        }

        for(int c = 0; c < nums.size(); ++c){
            for(size_t d = c + 1; d < nums.size(); ++d){
                const int key = target - nums[c] - nums[d];
                if(cache.find(key) == cache.end()){
                    continue;
                }
                const auto& vec = cache[key];
                for(size_t k = 0; k < vec.size(); ++k){
                    if(c <= vec[k].second){
                        continue;
                    }//有重叠

                    result.push_back({nums[vec[k].first],nums[vec[k].second],nums[c],nums[d]});
                }
            }
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(),result.end()), result.end());
        return result;
    }
};

//multimap 做缓存

class Solution3{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(result.begin(), result.end());

        unordered_multimap<int, pair<int, int>> cache;
        for(size_t i = 0; i + 1 < nums.size(); ++i){
            for(size_t j = i + 1; j < nums.size(); ++j){
                cache.insert(make_pair(nums[i]+nums[j], make_pair(i,j)));
            }
        }

        for(auto i = cache. begin(); i != cache.end(); ++i){
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for(auto j = range.first; j != range.second; ++j){
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;

                if(a != c && a != d && b != c && b != d){
                    vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
                    sort(vec.begin(), vec.end());
                    result.push_back(vec);
                }
            }
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(),result.end()), result.end());
        return result;
    }
};

//方法4
class Solution4{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target){
            vector<vector<int>> result;
            if(nums.size() < 4) return result;
            sort(nums.begin(), nums.end());

            auto last = nums.end();
            for(auto a = nums.begin(); a < prev(last,3); a = upper_bound(a, prev(last, 3), *a)){
                for(auto b = next(a); b < prev(last,2); b = upper_bound(b, prev(last, 2), *b)){
                    auto c = next(b);
                    auto d = prev(last);

                    while(c < d){
                        if(*a + *b + *c + *d < target){
                            c = upper_bound(c, d, *c);
                        }else if(*a + *b + *c + *d > target){
                            d = prev(lower_bound(c, d, *d));
                        }else{
                            result.push_back({*a, *b, *c, *d});
                            c = upper_bound(c, d, *c);
                            d = prev(lower_bound(c, d, *d));
                        }
                    }
                }
            }
            return result;
        }
};

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    Solution1 solver1;
    Solution2 solver2;
    Solution3 solver3;
    Solution4 solver4;

    vector<vector<int>> res1 = solver1.fourSum(nums,target);
    vector<vector<int>> res2 = solver2.fourSum(nums,target);
    vector<vector<int>> res3 = solver3.fourSum(nums,target);
    vector<vector<int>> res4 = solver4.fourSum(nums,target);

    for(int i = 0; i < res1.size(); ++i){
        for(int j = 0; j < res1[0].size(); ++j){
            cout << res1[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < res2.size(); ++i){
        for(int j = 0; j < res2[0].size(); ++j){
            cout << res2[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < res3.size(); ++i){
        for(int j=0; j < res3[0].size(); ++j){
            cout << res3[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < res4.size(); ++i){
        for(int j=0; j < res4[0].size(); ++j){
            cout << res4[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
