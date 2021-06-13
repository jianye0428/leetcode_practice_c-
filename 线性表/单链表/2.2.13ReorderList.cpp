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
    void reorderList(ListNode *head){
        if(head == nullptr){
            return;
        }
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        slow = reverse(slow);
        //merge two lists
        ListNode *curr = head;
        while(curr->next){
            ListNode *tmp = curr->next;
            curr->next = slow;
            slow = slow -> next;
            curr -> next -> next = tmp;
            curr = tmp;
        }
        curr -> next = slow;
    }
    
    ListNode *reverse(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *prev = head;
        for(ListNode *curr = head->next, *next = curr->next; curr; prev = curr, curr = next, next=next?next->next:nullptr){
            curr -> next = prev;
        }
        head->next = nullptr;
        return prev;
    }
};

int main()
{
    return 0;
}
