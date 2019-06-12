'''
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
'''

# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        if not pre:
            return None

        rootNode = TreeNode(pre[0])
        if len(pre) == 1:
            return rootNode
        
        rootSepIndex = tin.index(pre[0])
        leftTreeTin = tin[ : rootSepIndex]
        rightTreeTin = tin[rootSepIndex + 1 : ] if len(tin) > rootSepIndex + 1 else []
        
        rootSepIndex = len(leftTreeTin) + 1
        leftTreePre = pre[1 : rootSepIndex]
        rightTreePre = pre[rootSepIndex : ] if len(pre) > rootSepIndex else []
        
        rootNode.left = self.reConstructBinaryTree(leftTreePre, leftTreeTin)
        rootNode.right = self.reConstructBinaryTree(rightTreePre, rightTreeTin)
        return rootNode
