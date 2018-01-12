//
// Created by tayyebi on 1/12/18.
//

#include "BTree.h"


BTree::BTree()
{
    Root = NULL;
}

BTree::~BTree()
{
    DestroyTree();
}
void BTree::DestroyTree(node *Node)
{
    if(Node!=NULL)
    {
        DestroyTree(Node->Left);
        DestroyTree(Node->Right);
        delete Node;
    }
}
node * BTree::Insert(std::string Key, bool IsMeaning, node *Node)
{
    if(Key< Node->Key)
    {
        if(Node->Left!=NULL)
           return Insert(Key, IsMeaning, Node->Left);
        else
        {
            Node->Left=new node;
            Node->Left->Key=Key;
            Node->Left->IsMeaning=IsMeaning;
            Node->Left->Left=NULL;
            Node->Left->Right=NULL;
            return Node->Left;
        }
    }
    else if(Key>=Node->Key)
    {
        if(Node->Right!=NULL)
           return Insert(Key, IsMeaning, Node->Right);
        else
        {
            Node->Right=new node;
            Node->Right->Key=Key;
            Node->Right->IsMeaning=IsMeaning;
            Node->Right->Left=NULL;
            Node->Right->Right=NULL;
            return Node->Right;
        }
    }
}
node *BTree::Search(std::string Key, node *Node)
{
    if(Node!=NULL)
    {
        if(Key==Node->Key)
            return Node;
        if(Key<Node->Key)
            return Search(Key, Node->Left);
        else
            return Search(Key, Node->Right);
    }
    else return NULL;
}

node * BTree::Insert(std::string Key, bool IsMeaning)
{
    if(Root!=NULL)
       return Insert(Key, IsMeaning, Root);
    else
    {
        Root = new node;
        Root->Key=Key;
        Root->IsMeaning=IsMeaning;
        Root->Left=NULL;
        Root->Right=NULL;
        return Root;
    }

}

node *BTree::Search(std::string Key)
{
    return Search(Key, Root);
}

void BTree::DestroyTree()
{
    DestroyTree(Root);
}
