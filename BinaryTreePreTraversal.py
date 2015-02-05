# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        nodeList = []
        if root == None:
            return nodeList
        nodeList.append(root.val)
        nodeList+=self.preorderTraversal(root.left)
        nodeList+=self.preorderTraversal(root.right)
        return nodeList
