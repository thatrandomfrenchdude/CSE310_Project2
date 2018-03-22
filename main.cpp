//
//  main.cpp
//  Project02
//
//  Created by Nicholas Debeurre on 3/21/17.
//  Copyright © 2017 Samoji. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "main.hpp"
#include "heap.hpp"
#include "util.hpp"

using namespace std;

int main()
{
    //declares variables
    ifstream myFile ("HEAPinput.txt");
    Heap myHeap;
    int n;
    int b;
    int a;
    string line;
    int count = 0;
    
    char ch = 'i';
    do
    {
        cout << "Project 2 Main Menu\n";
        cout << "Pick a letter please\n";
        cout << "\tC n: creates a new array of size n\n";
        cout << "\tR: reads an array from the file and builds a heap\n";
        cout << "\tW: writes the current heap information to the screen\n";
        cout << "\tI k: inserts an element with value k into the heap\n";
        cout << "\tD: deletes the minimum element from the heap and prints the key of that element\n";
        cout << "\tK i v: decreases the key of the element at index i to the value v\n";
        cout << "\tS: Quit the program\n";
        cin >> ch;
        switch (ch)
        {
            case 'C':
            {
                cin >> n;
                if (count == 0)
                {
                    if (myFile.is_open())
                    {
                        getline(myFile, line);
                        b = stoi(line.c_str());
                        if (n < b)
                        {
                            n = b;
                        }
                        myHeap = Initialize(n);
                        cout << "\n";
                        count++;
                        break;
                    }
                    else
                    {
                        cout << "\nFile is not open or does not exist\n\n";
                        break;
                    }
                }
                else
                {
                    cout << "\nThe Heap has already been initialized\n\n";
                    break;
                }
            }
            case 'R':
            {
                Element *eArray = new Element[n];
                int j = 0;
                while(getline(myFile, line))
                {
                    b = stoi(line.c_str());
                    eArray[j].key = b;
                    j++;
                }
                Heap *temp = &myHeap;
                BuildHeap(temp, eArray, j);
                cout << "\n";
                delete[] eArray;
                eArray = NULL;
                myFile.close();
                break;
            }
            case 'W':
            {
                Heap *temp = &myHeap;
                printHeap(temp);
                cout << "\n";
                break;
            }
            case 'I':
            {
                cin >> b;
                Heap *temp = &myHeap;
                if (temp -> size == temp -> capacity)
                {
                    cout << "\nCould not insert key, heap is full.\n\n";
                    break;
                }
                Insert(temp, b);
                cout << "\n";
                break;
            }
            case 'D':
            {
                Heap *temp = &myHeap;
                if (temp -> size == 0)
                {
                    cout << "Error: the heap is empty.\n\n";
                    break;
                }
                b = DeleteMin(temp);
                cout << "\ndelete " << b << "\n\n";
                break;
            }
            case 'K':
            {
                cin >> b; //index
                b = b -1;
                cin >> a; //new key value
                Heap *temp = &myHeap;
                DecreaseKey(temp, b, a);
                cout << "\n";
                break;
            }
            case 'S':
            {
                delete[] myHeap.H;
                break;
            }
            default:
                cout << "\nInvalid input: Please use uppercase letters!\n\n";
        }
    } while (ch != 'S');
    return 0;
}
