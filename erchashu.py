# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# def postorderTraversal(root):
#     if root is None:
#         return []
#     result = []
#     result.extend(postorderTraversal(root.left))
#     result.extend(postorderTraversal(root.right))
#     result.append(root.val)
#     return result
#
# # 构建示例树
# A = TreeNode('A')
# B = TreeNode('B')
# C = TreeNode('C')
# D = TreeNode('D')
# E = TreeNode('E')
# F = TreeNode('F')
# G = TreeNode('G')
#
# A.left = B
#
# B.left = E
# B.right = C
# C.right = D
# E.right = F
# F.right = G
#
#
# # 执行后序遍历
# print(postorderTraversal(A))

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def buildTree(preorder, inorder):
    if not preorder or not inorder:
        return None

    # 先序遍历的第一个值是根节点
    root = TreeNode(preorder[0])
    # 在中序遍历中找到根节点的位置
    mid = inorder.index(preorder[0])

    # 递归构建左子树和右子树
    root.left = buildTree(preorder[1:mid + 1], inorder[:mid])
    root.right = buildTree(preorder[mid + 1:], inorder[mid + 1:])

    return root


def countLeaves(root):
    if not root:
        return 0
    if not root.left and not root.right:
        return 1
    return countLeaves(root.left) + countLeaves(root.right)


# 先序遍历序列
preorder = ['B', 'E', 'F', 'K', 'L', 'C', 'G', 'D', 'H', 'I', 'J']
# 中序遍历序列
inorder = ['E', 'K', 'L', 'F', 'B', 'G', 'C', 'H', 'I', 'D', 'J']

# 构建二叉树
root = buildTree(preorder, inorder)
def printTree(root):
    if not root:
        return

    def get_depth(node):
        if not node:
            return 0
        return max(get_depth(node.left), get_depth(node.right)) + 1

    def fill_values(node, depth, pos, arr, space_between):
        if not node:
            return
        index = pos + (space_between // 2)
        arr[depth][index] = str(node.val)
        fill_values(node.left, depth + 1, pos, arr, space_between // 2)
        fill_values(node.right, depth + 1, pos + space_between // 2 + 1, arr, space_between // 2)

    depth = get_depth(root)
    width = 2 ** depth - 1
    arr = [[" " for _ in range(width)] for _ in range(depth)]

    fill_values(root, 0, 0, arr, width)

    for row in arr:
        print("".join(row))

# 使用上述定义的函数打印树结构
printTree(root)
# 计算叶子节点的数量
leaf_count = countLeaves(root)

print(f"该二叉树的叶子数为: {leaf_count}")