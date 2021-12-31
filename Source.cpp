#include "Console.hpp"
#include "TreeNode.hpp"

#include <numeric>

class Solution {
public:
  int minDepth(TreeNode* root) {
    if (!root)
      return 0;

    if (!root->left && !root->right)
      return 1;

    if (!root->left)
      return 1 + minDepth(root->right);

    if (!root->right)
      return 1 + minDepth(root->left);

    return 1 + std::min(minDepth(root->left), minDepth(root->right));
  }
};

int main() {

  return 0;
}
