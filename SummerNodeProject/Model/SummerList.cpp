//
//  SummerList.cpp
//  SummerNodeProject
//
//  Created by Henrichsen, Cody on 7/27/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "SummerList.hpp"
#include <assert.h>

template <class Type>
SummerList<Type> :: SummerList()
{
    size = 0;
    front = nullptr;
    end = nullptr;
}

template <class Type>
void SummerList<Type> ::   addAtIndex(int index, Type data)
{
    assert(index >= 0 && index <= size);
    //Different than array -- we can dd to the end.
    DataNode<Type> * indexPointer = front;
    
    //Create a node.
    DataNode<Type> * newNode = new DataNode<Type>(data);
    
    if(index == 0)
    {
        addAtFront(data);
    }
    else if(index == size-1)
    {
        add(data);
    }
    else
    {
    
    for(int position = 0; position < index - 1; position++)
    {
        indexPointer = indexPointer->getNodePointer();
    }
   
       
    DataNode<Type> * temp = indexPointer->getNodePointer();
    newNode->setNodePointer(temp);
        
    //Setting indexPointer to point the newNodes address
    indexPointer->setNodePointer(newNode);
        
    size++;
    }
    
}
template <class Type>
void SummerList<Type> :: add(Type data)
{
    DataNode<Type> * newNode = new DataNode<Type>(data);
    if(size == 0)
    {
        front = newNode;
        end = newNode;
    }
    else
    {
        end->setNodePointer(newNode);
        end = newNode;
    }
    size++;
}

template <class Type>
void SummerList<Type> :: addAtFront(Type data)
{
    //Create a node.
    DataNode<Type> * newNode = new DataNode<Type>(data);
    if(size == 0)
    {
        front = newNode;
        end = newNode;
    }
    else
    {
        newNode->setNodePointer(front);
        front = newNode;
    }
    size++;
}

template <class Type>
Type SummerList<Type> :: remove(int index)
{
    assert(index >= 0 && index < size);
    
    Type removedValue;
    
    DataNode<Type> * indexPointer = front;
    DataNode<Type> * removedNode = nullptr;
    DataNode<Type> * next = nullptr;
    
    if (index == 1)
    {
        removedValue = front->getNodeData();
        
        delete indexPointer;
        
        front = nullptr;
        end = nullptr;
    }
    else if (index == 0)
    {
        removedValue = front->getNodeData();
        
        front = front->getNodePointer();
        
        delete indexPointer;
    }
    else
    {
        for(int position = 0; position < index - 1; position++)
        {
            indexPointer = indexPointer->getNodePointer();
        }
        
        removedNode = indexPointer->getNodePointer();
        next = removedNode->getNodePointer();
        
        if(removedNode == end)
        {
            end = indexPointer;
        }
        
        indexPointer->setNodePointer(next);
        removedNode->setNodePointer(nullptr);
        
        removedValue = removedNode->getNodeData();
        
        delete removedNode;
    }
    
    
    size--;
    return removedValue;
}