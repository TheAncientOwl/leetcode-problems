#include "Console.hpp"
#include "TreeNode.hpp"

#include <numeric>

/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 *   a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 * Example 2:
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 * Example 3:
 * Input: root = []
 * Output: true
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 5000].
 * -104 <= Node.val <= 104
*/

class Solution {
private:
  int getDepth(TreeNode* node, bool& out) {
    if (!node || !out)
      return 0;

    int left = this->getDepth(node->left, out);
    int right = this->getDepth(node->right, out);

    if (std::abs(left - right) > 1)
      out = false;

    return 1 + std::max(left, right);
  }

public:
  bool isBalanced(TreeNode* root) {
    if (!root)
      return true;

    bool result = true;
    this->getDepth(root, result);

    return result;
  }
};

int main() {

  return 0;
}
