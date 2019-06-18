'''
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
'''

# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isSubTree(self, pRoot1, pRoot2):
        # print("\t\tisSubTree: ", pRoot1.val if pRoot1 else 0, pRoot2.val if pRoot2 else 0)
        if not pRoot2:
            return True
        if not pRoot1:
            return False
        if pRoot1.val != pRoot2.val:
            return False
        return self.isSubTree(pRoot1.left, pRoot2.left) and \
                self.isSubTree(pRoot1.right, pRoot2.right)
    
    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        if not pRoot1 or not pRoot2:
            return False
        # print(">>> HasSubtree: ", pRoot1.val, pRoot2.val)
        return self.isSubTree(pRoot1, pRoot2) or \
                self.HasSubtree(pRoot1.left, pRoot2) or \
                self.HasSubtree(pRoot1.right, pRoot2)

# def load(tree, idx):
#     if idx >= len(tree):
#         return None
#     if tree[idx] == '#':
#         return None
#     root = TreeNode(tree[idx])
#     root.left = load(tree, idx * 2 + 1)
#     root.right = load(tree, (idx + 1) * 2)
#     return root

# pRoot1 = load([8,8,7,9,2,'#','#','#','#',4,7], 0)
# pRoot2 = load([8,9,2], 0)
# Solution().HasSubtree(pRoot1, pRoot2)
