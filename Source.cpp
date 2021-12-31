#include "TreeNode.hpp"
#include <limits>
#include <numeric>

class Solution {
public:
  int maxAncestorDiff(TreeNode* root, int min = INT_MAX, int max = INT_MIN) {
    if (!root)
      return max - min;

    min = std::min(min, root->val);
    max = std::max(max, root->val);

    return std::max(maxAncestorDiff(root->left, min, max), maxAncestorDiff(root->right, min, max));
  }
};

int main() {

  return 0;
}
