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
        
        if root is None:
            return
        
        output = [] # return list
        # create an empty stack and push root to it
        nodeStack = [] 
        nodeStack.append(root)
       
        """ 
          Pop all items one by one. Do following for every popped item 
             a) print it 
             b) push its right child 
             c) push its left child 
           Note that right child is pushed first so that left 
           is processed first */     
        """
        while(len(nodeStack) > 0):
            # Pop the top item from stack and put in output
            node = nodeStack.pop() 
            output.append(node.val)
            
            # Push right and left children of the popped node 
            # to stack 
            if node.right is not None: 
                nodeStack.append(node.right) 
            if node.left is not None: 
                nodeStack.append(node.left)
                
        return output