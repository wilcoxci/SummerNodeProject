//
//  SummerArray.cpp
//  SummerNodeProject
//
//  Created by Henrichsen, Cody on 7/27/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "SummerArray.hpp"

template <class Type>
SummerArray<Type> :: SummerArray(int length)
{
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
