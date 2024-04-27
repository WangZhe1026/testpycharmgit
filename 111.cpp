#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新节点
TreeNode* newNode(char data) {
    if (data == '#') return NULL; // '#' 表示空节点
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 构建二叉树
TreeNode* buildTree(const char **preorder) {
    if (**preorder == '\0') return NULL;
    char val = **preorder;
    (*preorder)++;  // 移动到下一个字符
    if (val == '#') return NULL;
    TreeNode *root = newNode(val);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// 交换左右子树
void swapChildren(TreeNode *root) {
    if (root == NULL) return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapChildren(root->left);
    swapChildren(root->right);
}

// 中序遍历并计算叶子节点数量
int leafCount = 0;
void inorderTraversal(TreeNode *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    if (root->left == NULL && root->right == NULL) leafCount++;
    inorderTraversal(root->right);
}

// 计算树的深度
int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    char input[41];
    scanf("%s", input);
    const char *p = input;

    TreeNode *root = buildTree(&p);
    swapChildren(root);
    inorderTraversal(root);
    printf("\n%d\n", leafCount);
    printf("%d\n", maxDepth(root));
    return 0;
}