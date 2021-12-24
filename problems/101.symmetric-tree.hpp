#include "TreeNode.hpp"

/**
 * Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 * Example 1:
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 * Example 2:
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
*/

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