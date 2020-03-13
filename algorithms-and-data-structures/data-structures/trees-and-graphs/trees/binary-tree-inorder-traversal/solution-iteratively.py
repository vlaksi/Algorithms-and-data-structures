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
        stack = []
        curr = root
        
        """
            While node is not null (terminal node) or stack is not empty 
            ( if we just say list, return value of list will say is it empty or not [False - it is empty, True- list have elements])
        """
        while curr is not None or stack:        
            while curr is not None:
                stack.append(curr)
                curr = curr.left
            
            curr = stack.pop(-1)                    # We take last element from stack
            output.append(curr.val)                 # and add that element to output
            curr = curr.right                       # so now we can go right
        
        return output