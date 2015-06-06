class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recordInorder(result, root);
        return result;
    }
private:
    void recordInorder(vector<int> &result, TreeNode* root){
        TreeNode* T = root;
        if(T == nullptr) return;
        recordInorder(result, T->left);
        result.push_back(T->val);
        recordInorder(result, T->right);
    }
};
