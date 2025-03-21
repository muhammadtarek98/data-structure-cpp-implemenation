//
// Created by muhammad on 21/03/25.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include<bits/stdc++.h>
struct nodeType
{
    int     info;
    nodeType  *left;
    nodeType  *right;
};
class binarySearchTreeType
{
public:
    bool isEmpty();
    bool search(int);
    bool searchRec(int);
    void insert(int);
    void remove(int);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int treeHeight();
    int treeNodeCount();
    int treeLeavesCount();
    void clearTree();
    binarySearchTreeType();
    ~binarySearchTreeType();
private:
    nodeType *root;
    void clear(nodeType* &p);
    void inorder(nodeType *p);
    void preorder(nodeType *p);
    void postorder(nodeType *p);
    int height(nodeType *p);
    int max(int x, int y);
    int nodeCount(nodeType *p);
    int leavesCount(nodeType *p);
    void deleteFromTree(nodeType * &p);
    bool searchRecPriv(nodeType *, int);
};

#endif //BINARY_SEARCH_TREE_H
