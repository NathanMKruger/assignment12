//	Nathan Kruger
//  PriorityQueue.h
//  
//  Defines a binary heap based priority queue class.
//  It is a max-heap.
//  You SHOULD modify this file.
//
//  IMPORTANT NOTE: For this particular assignment you may not add
//  any additional utility functions.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef pq_hpp
#define pq_hpp

#include <algorithm> // for swap()
#include <vector>
#include <random>
#include <cassert>
#include <iostream>

using namespace std;

// Convenience macros; Note that we are using -1, +1, and +2 as modifiers here
// versus the pseudocode in Introduction to Algorithms Chapter 6 to allow
// our heap to start at location 0
#define parent(i) ((i - 1) / 2)
#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)

namespace csi281 {
    
    
    template <typename T>
    class PriorityQueue {
    public:
        
        // What is the maximum value in the priority queue?
        // In other words, what is the next value that would be popped?
        // TIP: See pseudocode in Introduction to Algorithm Chapter 6 page 163
        // for HEAP-MAXIMUM()
        // NOTE: Our heap starts at 0, not 1
        T peek() {
            // YOUR CODE HERE
			return heap[0]; //return value at start of the heap
        }
        
        // Remove the next element (max element) in the heap and return it
        // TIP: See pseudocode in Introduction to Algorithm Chapter 6 page 163
        // for HEAP-EXTRACT-MAX()
        // NOTE: Our heap starts at 0, not 1
        // NOTE: Do not worry about contracting the size of the backing vector
        // after a pop.
        T pop() {
            // YOUR CODE HERE
			T maximum = heap[0]; //start of the heap should be the highest value. set to a max variable
			heap[0] = heap[heapSize - 1]; //replace start of heap with end of heap
			heapSize = heapSize - 1; //decrease heap size by one
			maxHeapify(0); //call to maxHeapify function
			return maximum; //return the max value from the old heap start stored in the variable
        }
        
        // Put a new element into the priority queue
        // TIP: A combination of HEAP-INCREASE-KEY() and MAX-HEAP-INSERT()
        // in Intro to Algorithms Chapter 6; they set the last element to
        // -infinity; we will set our last element to *key*, and then float it up
        // as is done in HEAP-INCREASE-KEY()
        // NOTE: macro parent() is defined at the top of this file
        // NOTE: our last element is at heapSize after being push_back()ed onto
        // the end of the vector heap
        void push(T key) {
            // YOUR CODE HERE
			heapSize = heapSize + 1; //increase heap size by one
			
			int i = heapSize - 1; //set a value to be the end of the heap
			heap.push_back(key); //add new value "key" into the back of the heap
			while (i > 0 && heap[parent(i)] < heap[i])
			{
				swap (heap[i], heap[parent(i)]); //exchange heap location value with the location's parent's value
				i = parent(i); //change i from being heapSize - 1 to the new parent
			}
        }
        
        // How many items are in the priority queue?
        int getCount() {
            return heapSize;
        }
        
        // A debut print ouf of the contents of the heap
        void debugPrint() {
            for (auto item : heap) {
                cout << item << " ";
            }
            cout << endl;
        }
    
    private:
        
        // Push down the element at *i* to maintain the max-heap property
        // TIP: See pseudocode in Introduction to Algorithm Chapter 6 page 154
        // NOTE: Macros left() and right() are defined at the top of this file
        void maxHeapify(int i) {
            // YOUR CODE HERE
			int largest; //variable to keep track of the larger value
			  if (left(i) < heapSize && heap[left(i)] > heap[i]) //left side isn't larger than the heap & the lefthand value is larger than current heap
			  {
				  largest = left(i); //the larger value is to the left. keep going left through the tree
			}
			  else
			  {
				  largest = i; //currently at the larger value
			  }
			  if (right(i) < heapSize && heap[right(i)] > heap[largest]) //right side isn't larger than the heap & the righthand value is larger than current largest value
			  {
				  largest = right(i); //larger value is to the right. keep going right through the tree
			}
			  if (largest != i) //the current value being worked with is NOT the larger value
			  {
				swap (heap[i], heap[largest]); //exchange value of heap at location i with the location of the largest value
				maxHeapify(largest); //recusively call maxHeapify with largest being sent in for "int i"
			}
        }
        
        vector<T> heap;
        int heapSize = 0;
    };
    
    
}


#endif /* pq_hpp */
