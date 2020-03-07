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
        inorderNumber = []
        
        if(root != None):
            self.search(root.left, inorderNumber)
            inorderNumber.append(root.val)
            self.search(root.right, inorderNumber)
        return inorderNumber
    
    def search(self, root, inorderNumber):
        if not inorderNumber:
            inorderNumber = []
            
        if(root != None):
            self.search(root.left, inorderNumber)
            inorderNumber.append(root.val)
            self.search(root.right, inorderNumber)
            
        return inorderNumber