#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Utility function to create a new node
TreeNode* newNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to build tree using inorder and preorder traversals
TreeNode* buildTree(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end) {
        return NULL;
    }

    // The first element in preorder is the root, create node for it
    TreeNode* node = newNode(preorder[*preIndex]);
    (*preIndex)++;

    // If this node has no children then return
    if (start == end) {
        return node;
    }

    // Else find the index of this node in Inorder traversal
    int inIndex;
    for (inIndex = start; inIndex <= end; inIndex++) {
        if (inorder[inIndex] == node->data) {
            break;
        }
    }

    // Using index in Inorder traversal, construct left and right subtress
    node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

// A utility function to print inorder traversal of a binary tree
void printInorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}