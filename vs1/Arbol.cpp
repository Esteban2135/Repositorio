#include <iostream>
#include <cstdlib>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void printInorder() {
        inorderRec(root);
    }

private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    void inorderRec(TreeNode* root) {
        if (root) {
            inorderRec(root->left);
            std::cout << root->data << " ";
            inorderRec(root->right);
        }
    }
};

int main() {
    BinaryTree tree;

    std::cout << "Ingrese un numero :" << std::endl;

    int value;
    while (std::cin >> value) {
        tree.insert(value);
    }

    if (std::cin.fail()) {
        std::cout << "Error: Ingrese un numero" << std::endl;
    } else {
        std::cout << "Recorido accendente del arbol" << std::endl;
        tree.printInorder();
    }

    return 0;
}
