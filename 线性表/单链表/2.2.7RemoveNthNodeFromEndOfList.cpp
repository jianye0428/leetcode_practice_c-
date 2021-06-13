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
    ListNode *removeNthNodeFromEnd(ListNode *head, int n){
        ListNode dummy{-1};
        dummy.next = head;
        ListNode *p = &dummy, *q = &dummy;

        for(int i=0; i<n; i++){
            q = q->next;
        }

        while(q->next){
            p = p->next;
            q = q->next;
        }

        ListNode *tmp = p->next;  //
        p->next = p -> next ->next;
        delete tmp;
        return dummy.next;
    }    
};

int main()
{
    return 0;
}
