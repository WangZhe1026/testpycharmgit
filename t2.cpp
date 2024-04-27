#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree() {
    int data;
	cin>>data;
    if (data == 0) {
        return NULL;
    }

    Node* root = createNode(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        //cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
bool findAncestors(Node* root, int k) {
    if (root == NULL) {
        return false;
    }

    if (root->data == k || findAncestors(root->left, k) || findAncestors(root->right, k)) {
        cout << root->data << " ";
        return true;
    }

    return false;
}



int main() {
    Node* root = buildTree();
	int n;
	cin>>n;
 
    preorderTraversal(root);
    cout<<endl;
    int k;
	for(int i=0;i<n;i++){
		cin>>k;
		findAncestors(root, k);
		cout << endl;
	}
    return 0;
}