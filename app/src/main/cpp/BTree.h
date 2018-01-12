//
// Created by tayyebi on 1/12/18.
//
#include <string>

#ifndef BAQEMBOOGH_EXTENDEDBTREE_H
#define BAQEMBOOGH_EXTENDEDBTREE_H


#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif





struct node
{
    std::string Key;
    bool IsMeaning = false;
    node *Left;
    node *Right;
};

class BTree
{
    public:
        BTree();
        ~BTree();

        node * Insert(std::string Key, bool IsMeaning);
        node * Insert(std::string Key, bool IsMeaning, node *Node);

        node *Search(std::string Key);
        void DestroyTree();
        node *Root;
    private:
        node *Search(std::string Key, node *Node);
        void DestroyTree(node *Node);

};


#endif //BAQEMBOOGH_EXTENDEDBTREE_H
