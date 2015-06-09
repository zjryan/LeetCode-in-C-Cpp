/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* T = root;
        if(T == nullptr || T->left == nullptr) return;
        linkChildren(T);
        linkMid(T->left, T->right);
        linkNull(T);
    }
    
private:
    void linkChildren(TreeLinkNode* root){
        TreeLinkNode* T = root;
        if(T == nullptr || T->left == nullptr) return;
        T->left->next = T->right;
        linkChildren(T->left);
        linkChildren(T->right);
    }
    
    void linkMid(TreeLinkNode* l, TreeLinkNode* r){
        if(l == nullptr || l->left == nullptr) return;
        l->right->next = r->left;
        linkMid(l->right, r->left);
        linkMid(l->left, l->right);
        linkMid(r->left, r->right);
    }
    
    void linkNull(TreeLinkNode* root){
        TreeLinkNode* T = root;
        if(T == nullptr) return;
        T->next = nullptr;
        linkNull(T->right);
    }
};
