//
//  heap.cpp
//  Project02
//
//  Created by Nicholas Debeurre on 3/21/17.
//  Copyright © 2017 Samoji. All rights reserved.
//

#include <iostream>
#include <array>
#include <cmath>
#include "main.hpp"
#include "heap.hpp"
#include "util.hpp"

using namespace std;

Heap Initialize(int n)
{
    try
    {
        Heap heapers;
        heapers.capacity = n; //sets the heap capacity to be n
        heapers.size = 0; //sets the heap size to be 0
        heapers.H = new Element[n];
        return heapers; //returns the pointer to the heap
    }
    catch (std::bad_alloc bae)
    {
        cout << "\nError: Heap cannot allocate enough memory for n\n";
        cout << "Pick a new value of n\n";
        int x;
        cin >> x;
        Heap heapers = Initialize(x);
        return heapers;
    }
}

void BuildHeap(Heap *heap, Element e[], int j)
{
    //checks to make sure the heap is not empty
    if(heap -> capacity == 0)
    {
        cout << "Error: Heap does not exist\n";
    }
    else
    {
        heap -> size = j;
        //while the heap exists
        for(int i = 0; i < j; i++)
        {
            //copy the array into the heap
            heap -> H[i].key = e[i].key;
        }
        //for loop to build the heap
        for (int i = parent(heap -> size); i > -1; i--)
        {
            //heapify to make sure each node does not violate heap
            heapify(heap, i);
        }
    }
}

void Insert(Heap *heap, int k)
{
    //increase heap size
    heap -> size++;
    //creates the node index for the final node
    int node_index = heap -> size - 1;
    //while loop puts the node in its correct location
    while (node_index > 0 && (heap -> H[parent(node_index)].key > k))
    {
        heap -> H[node_index].key = heap -> H[parent(node_index)].key;
        heap -> H[parent(node_index)].key = k;
        node_index = parent(node_index);
    }
    //once the node is in place, copy the key into it
    heap -> H[node_index].key = k;
}

int DeleteMin(Heap *heap)
{
    //sets min to the key of the root
    int min = heap -> H[0].key;
    int heap_size = heap -> size;
    //copies the last node to the root
    heap -> H[0] = heap -> H[heap_size - 1];
    //"cuts off" the last node
    heap -> size--;
    //heapifies the heap to maintain heap order
    heapify(heap, 0);
    //return min
    return min;
}

void DecreaseKey(Heap *heap, int index, int value)
{
    //using a 0 based array, check to make sure array exists
    if (index == heap -> size)
    {
        cout << "Error: Element does not exist in the heap\n";
    }
    else
    {
        //checks to make sure the new key is smaller than current key
        if (value > heap -> H[index].key)
        {
            cout << "\nError: new key is larger than current key\n\n";
        }
        else
        {
            //adds the value to the proper node
            heap -> H[index].key = value;
            //moves the node to its proper position
            while (index > 0 && (heap -> H[parent(index)].key > heap -> H[index].key))
            {
                Element p_e = heap -> H[parent(index)];
                heap -> H[parent(index)] = heap -> H[index];
                heap -> H[index] = p_e;
                index = parent(index);
            }
        }
    }
}

void printHeap(Heap *heap)
{
    if (heap == NULL)
    {
        cout << "No heap has been initialized";
    }
    else
    {
        //prints out heap size
        cout << "\nHeap size: " << heap -> size << "\n";
        //prints out heap capacity
        cout << "Heap capacity: " << heap -> capacity << "\n";
        //prints out heap elements
        for (int i = 0; i < heap -> size; i++)
        {
            cout << heap -> H[i].key << " ";
        }
        cout << "\n";
    }
}
