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

class Solution{
public:
    vector<vector<int>> leverOrderBottom(TreeNode *root){
        vector<vector<int>> result;
        traverse(root, 1, result);
        std::reverse(result.begin(), result.end());
        return result;
    }
    void traverse(TreeNode *root, size_t level, vector<vector<int>>& result){
        if(!root) return;

        if(level > result.size()){
            result.push_back(vector<int>());
        }
        result[level-1].push_back(root->val);
        traverse(root->left, level+1, result);
        traverse(root->right, level+1, result);
    }
};
//Iteration
class Solution2{
    vector<vector<int>> levelOrderBottom(TreeNode *root){
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> current, next;
        vector<int> level;

        current.push(root);
        while(!current.empty()){
            while(!current.empty()){
                TreeNode *node = current.front();
                current.pop();
                level.push_back(node->val);

                if(node->left != nullptr) next.push(node->left);
                if(node->right != nullptr) next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(next, current);            
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    return 0;
}
