#include "TreeNode.hpp"
#include <numeric>

class Solution {
public:
  int maxDepth(TreeNode* root, int currentDepth = 1) {
    if (!root)
      return currentDepth - 1;

    currentDepth++;

    return std::max(maxDepth(root->left, currentDepth), maxDepth(root->right, currentDepth));
  }
};

int main() {

  return 0;
}
