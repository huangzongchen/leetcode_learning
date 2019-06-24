# Definition for a binary tree node.

class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None
         pass
     pass


class Solution:
    def __init__(self):
        self.kthmin = None
        self.count = 0
        pass
    def mid_root_traver(self, root, k):
        if (root.left != None):
            self.mid_root_traver(root.left, k)
            pass
        self.count += 1
        if (self.count == k) :
            self.kthmin = root.val
            return
            pass
        if (root.right != None):
            self.mid_root_traver(root.right, k)
            pass
        pass
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.mid_root_traver(root, k)
        return self.kthmin
        pass


if __name__ == '__main__':
    root = TreeNode(3)
    node1 = TreeNode(3)
    solution = Solution()
    print(solution.kthSmallest(root, 1))
    pass