/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> temp;
        vector<TreeNode*> temp_vector;
        int flag = 0;
        if (root == NULL) {
            return ret;
        }
        //temp.push_back(root->val);
        temp_vector.push_back(root);
        //ret.push_back(temp);
        //temp.clear();
        //flag ++;
        while (!temp_vector.empty()) {
            //遍历当前层级，将数值存储到临时的vector中
            vector<TreeNode*> temp_vector_1;
            for (vector<TreeNode*>::iterator iter = temp_vector.begin(); iter != temp_vector.end(); iter++) {
                temp.push_back((*iter)->val);
                //如果左右子树指针不为空，则入临时vector
                if ((*iter)->left != NULL) temp_vector_1.push_back((*iter)->left);
                if ((*iter)->right != NULL) temp_vector_1.push_back((*iter)->right);
            }
            if ((flag % 2) == 1) {
                reverse(temp.begin(), temp.end());
            }
            flag+=1;
            ret.push_back(temp);   
            temp.clear();
            temp_vector = temp_vector_1;
        }      

        return ret;
    }
};

