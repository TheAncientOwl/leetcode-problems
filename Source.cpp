#include "Console.hpp"
#include "TreeNode.hpp"

#include <vector>

class Solution {
private:
  TreeNode* implSortedArrayToBST(int start, int end, const std::vector<int>& nums) {
    if (start >= end)
      return nullptr;

    int mid = start + ((end - start) / 2);

    TreeNode* newNode = new TreeNode(nums[mid]);
    newNode->left = implSortedArrayToBST(start, mid, nums);
    newNode->right = implSortedArrayToBST(mid + 1, end, nums);

    return newNode;
  }

public:
  TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    return implSortedArrayToBST(0, nums.size(), nums);
  }
};

int main() {

  return 0;
}
