# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        output = []
        self.search(root,output)
        return output
        """
            If node is not terminal, we can go further to that branch.
        """
    def search(self, node, output):
        if node is not None:
            output.append(node.val)
            if node.left is not None:
                self.search(node.left, output)
            if node.right is not None:
                self.search(node.right, output)