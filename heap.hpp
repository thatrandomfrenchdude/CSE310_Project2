//
//  heap.hpp
//  Project02
//
//  Created by Nicholas Debeurre on 3/21/17.
//  Copyright © 2017 Samoji. All rights reserved.
//
#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>

struct Element
{
    int key;
};

struct Heap
{
    int capacity;
    int size;
    struct Element *H;
};

Heap Initialize(int n);
void BuildHeap(Heap *heap, Element e[], int j);
void Insert(Heap *heap, int k);
int DeleteMin(Heap *heap);
void DecreaseKey(Heap *heap, int index, int value);
void printHeap(Heap *heap);

#endif /* heap_hpp */
