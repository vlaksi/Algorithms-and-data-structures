# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        if root == None:
            return []
        
        output = []            
        nodes = [root]
        
        while nodes:
            """
                With '[ node.val for node in nodes]' we get a list of the value of all nodes,
                and then append that list to output list.
            """
            level = [ node.val for node in nodes]
            output.append(level)
            
            nextNodes = []
            for node in nodes:
                if node.left:
                    nextNodes.append(node.left)
                if node.right:
                    nextNodes.append(node.right)
            nodes = nextNodes
        return output