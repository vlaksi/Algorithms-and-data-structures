# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return
        
        stack1 = []
        stack2 = []
        
        output = []
        stack1.append(root)
        
        while stack1:                   # Run while first stack is not empty 
            node = stack1.pop()         # take last element from first stack
            stack2.append(node)         # and push to second stack
                                        # Push left and right children of  
                                        # removed item to stack1 
            if node.left is not None:
                stack1.append(node.left)
            if node.right is not None:
                stack1.append(node.right)
                
        while stack2:                   # put value of element to output
            node = stack2.pop()
            output.append(node.val)
            
        return output
        
        