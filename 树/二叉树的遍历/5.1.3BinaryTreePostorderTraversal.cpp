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
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode *p = root, *q = nullptr;

        do{
            while(p != nullptr){
                s.push(p);
                p = p -> left;
            }
            q = nullptr;
            while(!s.empty()){
                p = s.top();
                s.pop();
                if(p->right == q){
                    result.push_back(p->val);
                    q = p;
                }else{
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        }while(!s.empty());
        return result;
    }
};

class Solution2{
public:
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> result;
        TreeNode dummy(-1);
        TreeNode *cur, *prev = nullptr;
        std::function<void(const TreeNode*)> visit = 
            [&result](const TreeNode *node){
            result.push_back(node->val);
        };

        dummy.left = root;
        cur = &dummy;
        while(cur != nullptr){
            if(cur->left == nullptr){
                prev = cur;
                cur = cur->right;
            }else{
                TreeNode *node = cur -> left;
                while(node->right != nullptr && node->right != cur){
                    node = node->right;
                }
                if(node->right == nullptr){
                    node->right = cur;
                    prev = cur;
                    cur = cur->left;
                }else{
                    visit_reverse(cur->left, prev, visit);
                    prev->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
private:
    static void reverse(TreeNode *from, TreeNode *to){
        TreeNode *x = from, *y = from->right, *z;
        if(from == to) return;

        while(x != to){
            z = y->right;
            y->right = x;
            x = y;
            y=z;
        }    
    }
    static void visit_reverse(TreeNode *from, TreeNode *to, std::function<void(const TreeNode*)>& visit){
        TreeNode *p = to;
        reverse(from, to);

        while(true){
            visit(p);
            if(p == from){
                break;
            }
            p = p->right;
        }

        reverse(to, from);
    }

};
int main()
{
    return 0;
}
