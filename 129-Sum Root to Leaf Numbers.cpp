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
    int sumNumbers(TreeNode* root) {
        vector<int> container;
        downToLeaf(root, container, "");
        int result = 0;
        for(int elem : container)
            result += elem;
        return result;
    }
private:
    void downToLeaf(TreeNode* root, vector<int> &nums, string str){
        TreeNode* T = root;
        string curstr = str;
        if(T == nullptr) return;
        curstr += (T->val + '0');
        
        downToLeaf(T->right, nums, curstr);
        downToLeaf(T->left, nums, curstr);
        if(T->left == nullptr && T->right == nullptr) {// T now is a leaf
            nums.push_back(atoi(curstr.c_str()));
            return;
        }
    }
};
