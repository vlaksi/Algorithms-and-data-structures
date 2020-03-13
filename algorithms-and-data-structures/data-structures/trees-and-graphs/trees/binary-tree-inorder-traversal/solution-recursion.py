# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        output = []
        self.search(root,output)
        return output
    
    def search(self, node, output):
        if node is not None :
            if node.left is not None:
                self.search(node.left, output)
            output.append(node.val)
            if node.right is not None:
                self.search(node.right, output)