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
    vector<int> TreeVec;
    void Traver(TreeNode* root){        
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
                 
            Traver(root->left);
            //TreeVec.push_back(root->left->val);        
            
        }
        TreeVec.push_back(root->val);

        if (root->right != NULL) {
            Traver(root->right);
            //TreeVec.push_back(root->right->val);
        }       
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        Traver(root);
        return TreeVec;
    }
};