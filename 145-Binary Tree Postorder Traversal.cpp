class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        recordPostorder(result, root);
        return result;
    }
private:
    void recordPostorder(vector<int> &result, TreeNode* root){
        TreeNode* T = root;
        if(T == nullptr) return;
        recordPostorder(result, T->left);
        recordPostorder(result, T->right);
        result.push_back(T->val);
    }
};
