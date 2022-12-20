#ifndef BST_H
#define BST_H

#include <iostream>
#include <algorithm>

template <typename T, typename Comparator=std::less<T>>
class BST {
public:
    BST();
    BST(const BST&);
    BST(BST&&);
    ~BST();

    BST& operator=(const BST&);
    BST& operator=(BST&&);

    const T& find_max() const;
    const T& find_min() const;

    bool contains(const T&) const;
    bool is_empty() const;

    void clear();
    void insert(const T&);
    void insert(T&&);
    void remove(const T&);

    void inorder();
    void preorder();
    void postorder();
private:
    struct TreeNode {
        TreeNode(T v = T(), TreeNode* l = nullptr, TreeNode* r = nullptr) : val(v), left(l), right(r) {} 
        T val;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    Comparator is_less_than;
private:
    void insert(const T&, TreeNode*&);
    void insert(T&&, TreeNode*&);
    void remove(const T&, TreeNode*&);
    bool contains(const T&, TreeNode*) const;
    TreeNode* find_min(TreeNode*) const;
    TreeNode* find_max(TreeNode*) const;
    void make_empty(TreeNode*);
    TreeNode* clone(TreeNode*) const;
    void inorder(TreeNode*);
    void preorder(TreeNode*);
    void postorder(TreeNode*);
};
#include "bst.hpp"
#endif // BST_H