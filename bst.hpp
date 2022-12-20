#include "bst.h"

template <typename T, typename Comparator>
BST<T, Comparator>::BST() : root(nullptr), is_less_than() {}

template <typename T, typename Comparator>
BST<T, Comparator>::BST(const BST& tree) : root(nullptr) {
    root = clone(tree.root);
}

template <typename T, typename Comparator>
BST<T, Comparator>::BST(BST&& tree) : root(nullptr) {
    root = tree.root;
    tree.root = nullptr;
}

template <typename T, typename Comparator>
BST<T, Comparator>::~BST() {
    make_empty(root);
}

template <typename T, typename Comparator>
BST<T, Comparator>& BST<T, Comparator>::operator=(const BST& tree) {
    if (this != &tree) {
        root = clone(tree.root);
    }
    return *this;
}

template <typename T, typename Comparator>
BST<T, Comparator>& BST<T, Comparator>::operator=(BST&& tree) {
    if (this != &tree) {
        root = tree.root;
        tree.root = nullptr;
    }
    return *this;
}

template <typename T, typename Comparator>
bool BST<T, Comparator>::contains(const T& val) const {
    return contains(val, root);
}

template <typename T, typename Comparator>
bool BST<T, Comparator>::contains(const T& val, BST<T, Comparator>::TreeNode* root) const {
    if (!root) {
        return false;
    }
    else if (is_less_than(val, root->val)) {
        return contains(val, root->left);
    } 
    else if (is_less_than(root->val, val)) {
        return contains(val, root->right);
    }
    return true;
}

template <typename T, typename Comparator>
const T& BST<T, Comparator>::find_max() const {
    return find_max(root);
}

template <typename T, typename Comparator>
const T& BST<T, Comparator>::find_min() const {
    return find_min(root);
}

template <typename T, typename Comparator>
void BST<T, Comparator>::insert(const T& val) {
    insert(val, root);
}

template <typename T, typename Comparator>
void BST<T, Comparator>::insert(T&& val) {
    insert(val, root);
}

template <typename T, typename Comparator>
void BST<T, Comparator>::remove(const T& val) {
    remove(val, root);
}

template <typename T, typename Comparator>
void BST<T, Comparator>::clear() {
    make_empty(root);
}

template <typename T, typename Comparator>
bool BST<T, Comparator>::is_empty() const {
    return root == nullptr;
}

template <typename T, typename Comparator>
typename BST<T, Comparator>::TreeNode* BST<T, Comparator>::find_min(TreeNode* root) const {
    if (!root) {
        return nullptr;
    }
    if (!root->left) {
        return root;
    }
    return find_min(root->left);
}   

template <typename T, typename Comparator>
typename BST<T, Comparator>::TreeNode* BST<T, Comparator>::find_max(TreeNode* root) const {
    if (!root) {
        return nullptr;
    }
    if (!root->right) {
        return root;
    }
    return find_max(root->right);
}

template <typename T, typename Comparator>
void BST<T, Comparator>::insert(const T& val, TreeNode*& root) {
    if (!root) {
        root = new TreeNode(val, nullptr, nullptr);
    } else if (val < root->val) {
        insert(val, root->left);
    } else {
        insert(val, root->right);
    }
}

template <typename T, typename Comparator>
void BST<T, Comparator>::insert(T&& val, TreeNode*& root) {
    if (!root) {
        root = new TreeNode(std::move(val), nullptr, nullptr);
    } else if (val < root->val) {
        insert(std::move(val), root->left);
    } else {
        insert(std::move(val), root->right);
    }
}

template <typename T, typename Comparator>
void BST<T, Comparator>::remove(const T& val, TreeNode*& root) {
    if (!root) {
        return;
    }
    if (val < root->val) {
        remove(val, root->left);
    }
    else if (val > root->val) {
        remove(val, root->right);
    } 
    else if (root->left != nullptr && root->right != nullptr) {
        root->val = find_min(root->right)->val;
        remove(root->val, root->right);
    } else {
        TreeNode* oldNode = root;
        root = (root->left != nullptr) ? root->left : root->right;
        delete oldNode;
    }

}

template <typename T, typename Comparator>
void BST<T, Comparator>::make_empty(TreeNode* root) {
    if (root) {
        make_empty(root->left);
        make_empty(root->right);
        delete root;
    }
    root = nullptr;
}

template <typename T, typename Comparator>
typename BST<T,Comparator>::TreeNode* BST<T, Comparator>::clone(TreeNode* root) const {
    if (!root) {
        return nullptr;
    }
    return new TreeNode(root->val, clone(root->left), clone(root->right));
}

template <typename T, typename Comparator>
void BST<T, Comparator>::inorder(TreeNode* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    std::cout << root->val << "  ";
    inorder(root->right);
}

template <typename T, typename Comparator>
void BST<T, Comparator>::preorder(TreeNode* root) {
    if (!root) {
        return;
    }
    std::cout << root->val << "  ";
    preorder(root->left);
    preorder(root->right);

}

template <typename T, typename Comparator>
void BST<T, Comparator>::postorder(TreeNode* root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << "  ";
}

template <typename T, typename Comparator>
void BST<T, Comparator>::inorder() {
    inorder(root);
}

template <typename T, typename Comparator>
void BST<T, Comparator>::preorder() {
    preorder(root);   
}

template <typename T, typename Comparator>
void BST<T, Comparator>::postorder() {
    postorder(root);   
}