class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        recordPreorder(result, root);
        return result;
    }
private:
    void recordPreorder(vector<int> &result, TreeNode* root){
        TreeNode* T = root;
        if(T == nullptr) return;
        result.push_back(T->val);
        recordPreorder(result, T->left);
        recordPreorder(result, T->right);
    }
};
