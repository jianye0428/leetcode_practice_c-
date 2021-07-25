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
    // 前序遍历
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> result;
        stack<const TreeNode *> s;
        if(root != nullptr){
            s.push(root);
        }

        while(!s.empty()){
            const TreeNode *p = s.top();
            s.pop();
            result.push_back(p->val);
            if(p->right != nullptr) s.push(p->right);
            if(p->left != nullptr) s.push(p->left);
        }
        return result;
    }
};

class Solution2{
public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> result;
        TreeNode *cur = root, *prev = nullptr;
        while(cur != nullptr){
            if(cur->left == nullptr){
                result.push_back(cur->val);
                prev = cur;/*cur 刚刚被访问过*/
                cur = cur->right;
            }else{
                /*查找前驱*/
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur){
                    node = node->right;
                }
                if(node->right == nullptr){
                    result.push_back(cur->val);
                    node->right = cur;
                    prev = cur; /*cur was visited*/
                    cur = cur->left;
                }else{
                    node->right = nullptr;
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
