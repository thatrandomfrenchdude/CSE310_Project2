//
//  util.cpp
//  Project02
//
//  Created by Nicholas Debeurre on 3/21/17.
//  Copyright © 2017 Samoji. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "main.hpp"
#include "heap.hpp"
#include "util.hpp"

using namespace std;

void heapify(Heap *heap, int i)
{
    //finds the left child of the parent
    int left_child = left(i);
    //finds the right child of the parent
    int right_child = right(i);
    int smallest;
    //find the largest value between the two keys at the index and the left child
    if ((left_child < heap -> size) && (heap -> H[left_child].key < heap -> H[i].key))
    {
        smallest = left_child;
    }
    else
    {
        smallest = i;
    }
    //finds the largest values between the right child key and the current largest value
    if ((right_child < heap -> size) && (heap -> H[right_child].key < heap -> H[smallest].key))
    {
        smallest = right_child;
    }
    //swaps the largest value with the index and calls heapify again
    if (smallest != i)
    {
        //swaps the values of i and largest
        int key_save = heap -> H[i].key;
        heap -> H[i].key = heap -> H[smallest].key;
        heap -> H[smallest].key = key_save;
        //recursively calls heapify again
        heapify(heap, smallest);
    }
}

//find the parent of selected index
int parent(int i)
{
    return floor((i-1)/2);
}

//finds left child of selected index
int left(int i)
{
    return (2*i)+1;
}

//finds right child of selected index
int right(int i)
{
    return ((2*i)+2);
}
