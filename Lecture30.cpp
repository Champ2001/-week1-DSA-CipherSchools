// Q2 Kth smallest element problem

#include <bits/stdc++.h>
using namespace std;

void swap(int* x, int* y);
class MinHeap {

	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	MinHeap(int a[], int size); // Constructor
	void MinHeapify(int i);
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	int extractMin(); // extracts root (minimum) element
	int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size)
{
	heap_size = size;
	harr = a; 
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		MinHeapify(i);
		i--;
	}
}
int MinHeap::extractMin()
{
	if (heap_size == 0)
		return INT_MAX;
	int root = harr[0];
	if (heap_size > 1) {
		harr[0] = harr[heap_size - 1];
		MinHeapify(0);
	}
	heap_size--;

	return root;
}
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < heap_size && harr[l] < harr[i])
		smallest = l;

	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int kthSmallest(int arr[], int N, int K)
{
	MinHeap mh(arr, N);
	for (int i = 0; i < K - 1; i++)
		mh.extractMin();
	return mh.getMin();
}
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 2;
	cout << "K'th smallest element is "<< kthSmallest(arr, N, K);
	return 0;
}

// Q3 Median for infinite integers
vector<double> medianOfRunningStream(vector<double> &vec){
    int N=vec.size();
    vector<double> medians(N);
    priority_queue<double> maxHeap;
    priority_queue<double,vector<double>,greater<double>> minHeap;
    maxHeap.push(vec[0]);
    medians[0]=vec[0];
    for(int i=0;i<N;i++){
        maxHeap.push(vec[i]);
        while(maxHeap.size()-minHeap.size()>1){
            double top=maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        if(i&1) medians[i]=maxHeap.top();
        else     medians[i]=(maxHeap.top()+minHeap.top())/2;
    }
    return medians;
}