#include <iostream>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Konstruktor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menambahkan node baru ke pohon biner
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Fungsi untuk melakukan traversal in-order
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Fungsi untuk melakukan traversal pre-order
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Fungsi untuk melakukan traversal post-order
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;
    
    return 0;
}
