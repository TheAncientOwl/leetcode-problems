#include "TreeNode.hpp"

class Solution {
private:
  bool isMirrored(TreeNode* p, TreeNode* q) {
    if (!p && !q)
      return true;

    if (!p || !q)
      return false;

    if (p->val != q->val)
      return false;

    return isMirrored(p->left, q->right) && isMirrored(p->right, q->left);
  }

public:
  bool isSymmetric(TreeNode* root) {
    if (!root)
      return true;

    if (!root->left && !root->right)
      return true;

    return isMirrored(root->left, root->right);
  }
};

int main() {


  return 0;
}