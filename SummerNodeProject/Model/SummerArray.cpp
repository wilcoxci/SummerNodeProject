//
//  SummerArray.cpp
//  SummerNodeProject
//
//  Created by Henrichsen, Cody on 7/27/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "SummerArray.hpp"
#include <assert.h>

template <class Type>
SummerArray<Type> :: SummerArray(int length)
{
    assert(length > 0);
    
    this->length = length;
    modifiedNodes = new bool[length];
    front = nullptr;
    end = nullptr;
    
    DataNode<Type> * start = new DataNode<Type>();
    front = start;
    end = start;
    
    for(int index = 1; index < length; index++)
    {
        DataNode<Type> * next = new DataNode<Type>();
        end -> setNodePointer(next);
        end = next;
    }
    
}

template <class Type>
Type SummerArray<Type> :: getFromIndex (int index)
{
    assert(index >= 0);
    assert(index < length);
    
    Type retrievedValue;
    
    DataNode<Type> * indexPointer = front;
    for (int position = 0; position < index;
        position++)
    {
        indexPointer = indexPointer->getNodePointer ();
    }
    
    retrievedValue = indexPointer->getNodeData();
    
    return retrievedValue;
}

template <class Type>
Type SummerArray<Type> :: getFirst()
{
    return front->getNodeData();
}
template <class Type>
Type SummerArray<Type> :: getLast()
{ }
template <class Type>
    void SummerArray<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < length);
    
    DataNode<Type> * indexPointer = front;
    for(int position = 0; position < index; position++)
    {
        indexPointer = indexPointer->getNodePointer();
    }
    
    indexPointer->setNodeData(data);
}
template <class Type>
int SummerArray<Type> :: getLength()
{
    //instead of *nameOfArray/sizeof(type);
    return this->length;
}