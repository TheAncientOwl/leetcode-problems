#include "Console.hpp"
#include "TreeNode.hpp"

#include <numeric>

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
