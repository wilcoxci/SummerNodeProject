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
    
    
    for(int position = 0; position < index - 1; position++)
    {
        indexPointer = indexPointer->getNodePointer();
    }
   
    
    DataNode<Type> * newNode = new DataNode<Type>(data);
    
    newNode->setNodePointer(indexPointer->getNodePointer());
    
    //These two lines are the same things as previous line.
    //dataNode<Type> * temp = indexPointer->getNodePointer();
    //newNode->setNodePointer(temp);
    
}