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

class RandomListNode {
public:
    int val;
    RandomListNode* next;
    RandomListNode* random;
    
    RandomListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
    
};
class Solution{
public:
    RandomListNode *copyRandomList(RandomListNode *head){
        for(RandomListNode *cur = head; cur !=nullptr; ){
            RandomListNode *node = new RandomListNode(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        for(RandomListNode *cur = head; cur != nullptr;){
            if(cur->random != NULL){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        //分拆两个单链表
        RandomListNode dummy(-1);
        for(RandomListNode *cur = head, *new_cur = &dummy; cur != nullptr;){
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }

        return dummy.next;
    }
    
};

int main()
{
    return 0;
}
