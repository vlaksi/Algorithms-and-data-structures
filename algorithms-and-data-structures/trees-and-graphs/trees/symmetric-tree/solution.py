# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        if root == None:
            return True							# just because they want True if is input empty
        
        return self.mirror(root.left, root.right)
    
    def mirror(self, node1, node2):
        if node1 == None and node2 == None:
            return True
        if node1 == None or node2 == None:
            return False
        if node1.val != node2.val:
            return False
        
        return self.mirror(node1.left, node2.right) and self.mirror(node1.right, node2.left)
            
        
            
        