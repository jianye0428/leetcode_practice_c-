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
    ListNode *swapPairs(ListNode *head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;

        for(ListNode *prev = &dummy, *cur = prev->next, *next=cur->next;next;prev=cur, cur = cur->next, next = cur?cur->next:nullptr){
            prev->next = next;
            cur->next = next->next;
            next->next = cur; 
        }
        return dummy.next;
    }
    
};

int main()
{
    return 0;
}
