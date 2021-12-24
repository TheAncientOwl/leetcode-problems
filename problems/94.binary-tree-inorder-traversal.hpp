#include "TreeNode.hpp"

#include <vector>

class Solution {
private:
  void inorder(TreeNode* root, std::vector<int>& sln) {
    if (root != nullptr) {
      inorder(root->left, sln);
      sln.push_back(root->val);
      inorder(root->right, sln);
    }
  }

public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> sln;
    this->inorder(root, sln);
    return sln;
  }
};


int main() {

  return 0;
}