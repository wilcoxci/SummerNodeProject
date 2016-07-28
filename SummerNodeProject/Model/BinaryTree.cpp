//
//  BinaryTree.cpp
//  SummerNodeProject
//
//  Created by Henrichsen, Cody on 7/28/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "BinaryTree.hpp"

template <class Type>
BinaryTree<Type> :: BinaryTree()
{
    root = nullptr;
}

template <class Type>
void BinaryTree<Type> :: insert(Type data)
{
    BinaryTreeNode<Type> * insertedNode = new BinaryTreeNode<Type>(data);
    
    insert(insertedNode, root);
}

template <class Type>
void BinaryTree<Type> :: insert(BinaryTreeNode<Type> * insertedNode, BinaryTreeNode<Type> * currentRootNode)
{
    if(currentRootNode == nullptr)
    {
        currentRootNode = insertedNode;
    }
    else if (insertedNode->getNodeData() <currentRootNode->getNodeData())
    {
        insert(insertedNode, currentRootNode-> getLeftChild());
    }
    else if(insertedNode->getNodeData() > currentRootNode->getNodeData())
    {
        insert(insertedNode, currentRootNode-> getRightChild());
    }
}
