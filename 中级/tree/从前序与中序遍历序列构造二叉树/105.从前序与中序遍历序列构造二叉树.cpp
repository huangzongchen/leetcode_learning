/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* root = NULL;
    TreeNode* preroot;
public:
    void traver(vector<int>& preorder, vector<int>& inorder) {
        int root_val = -1;
        if (preorder.size() == 0) {
            return;
        }
        root_val = preorder[0];
        if (preorder.size() == 1) {
            preroot->val = root_val;
            preroot->left = NULL;
            preroot->right = NULL;
            return;
        }
        preorder.erase(preorder.begin());
        vector<int>::iterator iter;
        vector<int> left_inorder;
        vector<int> right_inorder;
        vector<int> left_preorder;
        vector<int> right_preorder;
        
        for (iter = inorder.begin(); iter != inorder.end(); iter++) {
            if (*iter == root_val) {
                left_inorder.assign(inorder.begin(), iter);
                 
                right_inorder.assign(iter+1, inorder.end()); 
                break;
            }
        }
        preroot->val = root_val;
        TreeNode* left_child = NULL;
        if (left_inorder.size() != 0) {
            left_preorder.assign(preorder.begin(), preorder.begin() + left_inorder.size());
            left_child =  new TreeNode(0);
            left_child->val = left_preorder[0];
            left_child->left = NULL;
            left_child->right = NULL;
            preroot->left = left_child;
            
        }
        TreeNode* right_child = NULL;
        if (right_inorder.size() != 0) {
            right_preorder.assign(preorder.begin()+left_inorder.size(), preorder.end());
            right_child =  new TreeNode(0);
            right_child->val = right_preorder[0];
            right_child->left = NULL;
            right_child->right = NULL;
            preroot->right = right_child;
            
        }
        if (left_child != NULL) {
            preroot = left_child;
            traver(left_preorder, left_inorder);
        }
        if (right_child != NULL) {
            preroot = right_child;
            traver(right_preorder, right_inorder);         
        }
               
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != 0) {
            root = new TreeNode(0);
            preroot = root; 
            traver(preorder, inorder);
        }
        
        return root;
    }
};

