/**
 * @brief Implements a binary heap data structure, including Max Heap and Min Heap variants, as well as Priority Queues.
 *
 * The `Heap` class is an abstract base class that provides the basic functionality for a binary heap. It includes methods for pushing and popping elements, getting the top element, and checking if the heap is empty. The `MaxHeap` and `MinHeap` classes inherit from `Heap` and implement the `heapUp` and `heapDown` methods to maintain the heap property.
 *
 * The `MinPriorityQueue` and `MaxPriorityQueue` classes are specialized versions of `MinHeap` and `MaxHeap`, respectively, that provide a priority queue interface.
 *
 * The implementation includes helper methods for managing the heap structure, such as `leftChild`, `rightChild`, and `parent`.
 */
#ifndef BINARY_HEAP_INCLUDED
#define BINARY_HEAP_INCLUDED

#include<iostream>
#include <vector>
using namespace std;

template<class T>
class Heap { 
protected:
   vector<T>heap;

   int leftChild (const int&);
   int rightChild (const int&);
   int parent (const int&);

   virtual void heapUp(const int&) = 0;
   virtual void heapDown(const int&) = 0;

   void pushItems (const vector<T>& ar);
   void pushItems (T ar[] , int N);

public:

   void push(const T&);
   void pop();
   T top() const;
   bool empty() const;
   int size() const;
}; // implementation of these function at the end this file

template<class T>
class MaxHeap : public Heap<T> {
public:
   MaxHeap() {};
   MaxHeap(const vector<T>&ar) {this->pushItems(ar);}
   MaxHeap(T ar[] , int N) {this->pushItems(ar,N);}
private:
   void heapUp(const int&);
   void heapDown(const int&);
};

template<class T>
class MinHeap : public Heap<T> {
public:
   MinHeap() {};
   MinHeap(const vector<T>&ar) {this->pushItems(ar);}
   MinHeap(T ar[] , int N) {this->pushItems(ar,N);}
private:
   void heapUp(const int&);
   void heapDown(const int&);
};

template<class T>
class MinPriorityQueue : public MinHeap<T> {
public:
   MinPriorityQueue() {};
   MinPriorityQueue(const vector<T>&ar) {this->pushItems(ar);}
   MinPriorityQueue(T ar[] , int N) {this->pushItems(ar,N);}
};

template<class T>
class MaxPriorityQueue : public MaxHeap<T> {
public:
   MaxPriorityQueue() {};
   MaxPriorityQueue(const vector<T>&ar) {this->pushItems(ar);}
   MaxPriorityQueue(T ar[] , int N) {this->pushItems(ar,N);}
};


// ========= Start Binary Heap implementation  ==========
template<class T>
int Heap<T>::size() const {
   return heap.size();
}
template<class T>
int Heap<T>::leftChild (const int&node) {
   int lfCh = (node << 1) + 1;
   return size() > lfCh ? lfCh : -1;
}
template<class T>
int Heap<T>::rightChild (const int&node) {
   int riCh = (node << 1) + 2;
   return size() > riCh ? riCh : -1;
}

template<class T>
int Heap<T>::parent (const int&node) {
   int p = ((node+1) >> 1) - 1;
   return node != 0 ? p : -1;
}
template<class T>
void Heap<T>::push (const T&val) {
   heap.push_back(val);
   heapUp(size() - 1);
}

template<class T>
void Heap<T>::pop () {
   heap[0] = heap.back();
   heap.pop_back();
   heapDown(0);
}

template<class T>
T Heap<T>::top() const {
   return heap.front();
}

template<class T>
bool Heap<T>::empty() const {
   return heap.empty();
}

template<class T>
void Heap<T>::pushItems (const vector<T>& ar) {
   int N = ar.size();
   for (int i = 0 ; i < N ; ++i)
      this->push(ar[i]);
}

template<class T>
void Heap<T>::pushItems (T ar[] , int N) {
   for (int i = 0 ; i < N ; ++i)
      this->push(ar[i]);
}
// ========= End Binary Heap implementation  ==========


// ========= Start Binary MAX Heap implementation  ==========
template<class T>
void MaxHeap<T>::heapUp(const int&pos) {
   if (pos == 0) return;
   
   int p = this->parent(pos);
   if (this->heap[pos] > this->heap[p]) {
      swap(this->heap[pos] , this->heap[p]);
      heapUp(p);
   }

}

template<class T>
void MaxHeap<T>::heapDown(const int&pos) {

   int lfCh = this->leftChild(pos);
   if (lfCh == -1) return;

   int riCh = this->rightChild(pos);
   if (riCh != -1 && this->heap[lfCh] < this->heap[riCh])
      lfCh = riCh;
   
   if (this->heap[pos] < this->heap[lfCh]) {
      swap(this->heap[lfCh] , this->heap[pos]);
      heapDown(lfCh);
   }
}
// ========= End Binary MAX Heap implementation  ==========

// ========= Start Binary MIN Heap implementation  ==========

template<class T>
void MinHeap<T>::heapUp(const int&pos) { 
   if (pos == 0) return;

   int p = this->parent(pos);

   if (this->heap[p] > this->heap[pos]) { 
      swap(this->heap[p] , this->heap[pos]);
      heapUp(p);
   }

}

template<class T>
void MinHeap<T>::heapDown(const int&pos) { 

   int lfCh = this->leftChild(pos);
   if (lfCh == -1) return;

   int riCh = this->rightChild(pos);
   if (riCh != -1 && this->heap[riCh] < this->heap[lfCh])
      lfCh = riCh;

   if (this->heap[pos] > this->heap[lfCh]) { 
      swap(this->heap[pos] , this->heap[lfCh]);
      heapDown(lfCh);
   }

}
// ========= End Binary MIN Heap implementation  ==========
#endif // BINARY_HEAP_INCLUDED