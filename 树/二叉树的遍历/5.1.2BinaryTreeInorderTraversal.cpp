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

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution1{
public:
   vector<int> inorderTraversal(TreeNode *root){
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode *p = root;
        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
   } 
};

class Solution2{
public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> result;
        TreeNode *cur = root, *prev = nullptr;
        while(cur != nullptr){
            if(cur->left == nullptr){
                result.push_back(cur->val);
                prev = cur;
                cur = cur->right;
            }else{
                /******/
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur){
                    node = node -> right;
                }
                if(node->right == nullptr){
                    node -> right = cur;
                    cur = cur->left;
                }else{
                    result.push_back(cur->val);
                    node->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}
