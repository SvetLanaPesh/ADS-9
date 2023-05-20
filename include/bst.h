// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };
 private:
    Node* root;
    Node* addNode(Node*, const T&);
    int depthNode(Node* root);
    int searchNode(Node* root, const T& value);
 public:
    BST();
    void add(const T& value);
    int depth();
    int search(T value);
    ~BST() {}
};
template <typename T>
BST<T>::BST(): root(nullptr) {}

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, const T& value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}

template <typename T>
void BST<T>::add(const T& value) {
    root = addNode(root, value);
}

template <typename T>
int BST<T>::depthNode(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(depthNode(root->left), depthNode(root->right));
}

template <typename T>
int BST<T>::depth() {
    return depthNode(root) - 1;
}
template <typename T>
int BST<T>::searchNode(Node* root, const T& value) {
    if (root == nullptr || root->value == value) {
        return root->count;
    } else if (root->value < value) {
        return searchNode(root->right, value);
    }
    return searchNode(root->left, value);
}

template <typename T>
int BST<T>::search(T value) {
    return searchNode(root, value);
}
#endif  // INCLUDE_BST_H_
