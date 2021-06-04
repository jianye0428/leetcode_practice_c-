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
    ListNode *deleteDuplicates(ListNode *head){
        if(!head) return head;
        ListNode dummy(head->val+1);
        dummy.next = head;

        recur(&dummy, head);
        return dummy.next;
    }
private:
    static void recur(ListNode *prev, ListNode *cur){
        if(cur == nullptr) return;

        if(prev->val == cur->val){
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        }else{
            recur(prev->next, cur->next);
        }
    }
};


class Solution2{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if(head == nullptr) return nullptr;

        for(ListNode *prev = head, *cur = head->next; cur; cur = prev->next){
            if(prev->val == cur->val){
                prev->next = cur->next;
                delete cur;
            }else{
                prev = cur;
            }
        }
        return head;
    }

};


int main()
{
    return 0;
}
