#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    int capacity;
    int size;
    int *heap;

    int parent(int index) {
        return (index - 1) / 2;
    }
    int leftChild(int index) {
        return (2 * index + 1);
    }
    int rightChild(int index) {
        return (2 * index + 2);
    }
    void minHeapify(int index) {
        int smallest = index;
        int l = leftChild(index);
        int r = rightChild(index);
        if (l < this->size && this->heap[smallest] > this->heap[l])
            smallest = l;
        if (r < this->size && this->heap[smallest] > this->heap[r])
            smallest = r;
        if (smallest != index) {
            swap(this->heap[index], this->heap[smallest]);
            minHeapify(smallest);
        }
    }
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        this->size = 0; // Initialize size to 0
        this->heap = new int[this->capacity];
    }
    void Push(int key) {
        if (this->size == this->capacity) {
            return;
        }
        this->size++;
        int index = this->size - 1;
        this->heap[index] = key;

        while (index != 0 && this->heap[index] < this->heap[parent(index)]) {
            swap(this->heap[index], this->heap[parent(index)]);
            index = parent(index);
        }
    }
    
    void Pop() {
        if (this->size == 0) {
            return;
        }
        if (this->size == 1) {
            this->size--;
            return;
        }
        this->heap[0] = this->heap[this->size - 1];
        this->size--;
        minHeapify(0);
    }
    int top() {
        return this->size == 0 ? 0 : this->heap[0];
        // or
        // if(this->size==0)   return -1;
        // return this->heap[0];
    }
};
