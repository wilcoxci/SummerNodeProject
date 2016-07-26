//
//  DataNode.cpp
//  SummerNodeProject
//
//  Created by Henrichsen, Cody on 7/26/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "DataNode.hpp"

// Constructors

template <class Type>
DataNode<Type> :: DataNode()
{
    //this->nodeData = 0: /* OK for int, double, boolean */
    this->nodePointer = nullptr;  /* or NULL instead of nullptr to point to nothing */
    
}
template <class Type>
DataNode<Type> :: DataNode(Type nodeData)
{
    this->nodeDatat = nodeData;
    this->nodeinter = nullptr;
}
//End constructors


//Getters and Setters

template <class Type>
Type DataNode<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
DataNode<Type> * DataNode<Type> :: getNodePointer()
{
    return nodePointer;
}

template <class Type>
void DataNode<Type> :: setNodeData(Type nodeData)
{
    this->nodeData = nodeData;
}

template <class Type>
void DataNode<Type> :: setNodePointer(DataNode<Type>* nodePointer)
{
    this->nodePointer = nodePointer;
}
//End getters and setter