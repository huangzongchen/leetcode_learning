/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
public:
    vector<Node*> node_vec;
    //广度优先搜索
    void traver(vector<Node*>& node_vec) {       
        if (node_vec.empty()) {
            return;
        }
        
        vector<Node*> tmp_node_vec;
        for (vector<Node*>::iterator iter = node_vec.begin(); iter != node_vec.end(); iter++) {
            if ((*iter)->left != NULL) tmp_node_vec.push_back((*iter)->left);
            if ((*iter)->right != NULL) tmp_node_vec.push_back((*iter)->right);
        }
        
        for (vector<Node*>::iterator iter = tmp_node_vec.begin(); iter != tmp_node_vec.end(); iter++) {
            vector<Node*>::iterator iter_tmp = (iter+1);
            if (iter_tmp != tmp_node_vec.end()) {                
                (*iter)->next = *iter_tmp;
            }
            else {
                (*iter)->next = NULL;
            }
        }
        node_vec = tmp_node_vec;

        traver(node_vec);       
    }

    void traver_no_recursion() {
        while (!node_vec.empty()) {
            vector<Node*> tmp_node_vec;
            for (vector<Node*>::iterator iter = node_vec.begin(); iter != node_vec.end(); iter++) {
                if ((*iter)->left != NULL) tmp_node_vec.push_back((*iter)->left);
                if ((*iter)->right != NULL) tmp_node_vec.push_back((*iter)->right);
            }
        
            for (vector<Node*>::iterator iter = tmp_node_vec.begin(); iter != tmp_node_vec.end(); iter++) {
                vector<Node*>::iterator iter_tmp = (iter+1);
                if (iter_tmp != tmp_node_vec.end()) {                
                    (*iter)->next = *iter_tmp;
                }
                else {
                    (*iter)->next = NULL;
                }
            }
            node_vec = tmp_node_vec;
        }
    }
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        node_vec.push_back(root);
        //traver(node_vec);
        traver_no_recursion();
        return root; 
    }
};

