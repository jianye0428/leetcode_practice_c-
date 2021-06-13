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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *next_group = head;

        for (int i = 0; i < k; ++i)
        {
            if (next_group)
            {
                next_group = next_group->next;
            }
            else
            {
                return head;
            }
        }

        ListNode *new_next_group = reverseKGroup(next_group, k);
        ListNode *prev = NULL, *cur = head;

        while (cur != next_group)
        {
            ListNode *next = cur->next;
            cur->next = prev ? prev : new_next_group;
            prev = cur;
            cur = prev;
        }
        return prev;
    }
};

class Solution2
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        for (ListNode *prev = &dummy, *end = head; end; end = prev->next)
        {
            for (int i = 1; i < k && end; i++)
            {
                end = end->next;
            }
            if(end == nullptr){
                break;// 不足k个
            }
            prev = reverse(prev, prev->next, end);
        }

        return dummy.next;
    }

    ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end)
    {
        ListNode *end_next = end->next;
        for (ListNode *p = begin, *cur = p->next, *next = cur->next;
             cur != end_next;
             p = cur, cur = next, next = next ? next->next : nullptr)
        {
            cur->next = p;
        }
        begin->next = end_next;
        prev->next = end;
        return begin;
    }
};
int main()
{
    return 0;
}
