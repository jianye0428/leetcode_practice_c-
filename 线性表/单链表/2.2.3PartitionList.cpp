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
    ListNode *partitionList(ListNode *head, int x){
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);

        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;

        for(ListNode *cur = head; cur; cur = cur -> next){
            if(cur -> val < x){
                left_cur -> next = cur;
                left_cur = cur;
            }else{
                right_cur -> next = cur; 
                right_cur = cur;
            }
        }
        left_cur -> next = right_dummy.next;
        right_cur -> next = nullptr;

        return left_dummy.next;
    }
};

int main()
{
    return 0;
}
