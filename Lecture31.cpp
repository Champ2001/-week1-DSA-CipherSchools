#include <iostream>
#include <vector>

class SegmentTree {
    int *arr;
    int arrSize;
    int *tree;
    int N;

public:
    int getLeftChild(int index) { return 2 * index + 1; }
    int getRightChild(int index) { return 2 * index + 2; }

    void buildTree(int nodeIndex, int start, int end) {
        if (start == end)
            this->tree[nodeIndex] = this->arr[start];
        else {
            int mid = start + (end - start) / 2;
            int leftIndex = getLeftChild(nodeIndex), rightIndex = getRightChild(nodeIndex);
            buildTree(leftIndex, start, mid);
            buildTree(rightIndex, mid + 1, end);

            this->tree[nodeIndex] = this->tree[leftIndex] + this->tree[rightIndex];
        }
    }

    void updateTree(int nodeIndex, int start, int end, const int &indexToUpdate, const int &delta) {
        if (indexToUpdate < start || indexToUpdate > end)
            return;

        this->tree[nodeIndex] += delta;
        if (start < end) {
            int mid = start + (end - start) / 2;
            int leftIndex = getLeftChild(nodeIndex), rightIndex = getRightChild(nodeIndex);

            if (start <= indexToUpdate && indexToUpdate <= mid) {
                updateTree(leftIndex, start, mid, indexToUpdate, delta);
            } else {
                updateTree(rightIndex, mid + 1, end, indexToUpdate, delta);
            }
        }
    }

    int getSum(int nodeIndex, int start, int end, const int &qStart, const int &qEnd) {
        if (qStart > end || qEnd < start)
            return 0;
        else if (qStart <= start && end <= qEnd)
            return this->tree[nodeIndex];
        else {
            int mid = start + (end - start) / 2;
            int leftIndex = getLeftChild(nodeIndex), rightIndex = getRightChild(nodeIndex);
            return getSum(leftIndex, start, mid, qStart, qEnd) + getSum(rightIndex, mid + 1, end, qStart, qEnd);
        }
    }

    SegmentTree(int *arr, int arrSize) {
        this->arrSize = arrSize;
        this->N = 4 * this->arrSize;
        this->arr = arr;
        this->tree = new int[this->N];
        for (int i = 0; i < this->N; i++)
            this->tree[i] = 0;
        buildTree(0, 0, this->arrSize - 1);
    }

    void Update(int indexToUpdate, int delta) {
        this->arr[indexToUpdate] += delta;
        updateTree(0, 0, this->arrSize - 1, indexToUpdate, delta);
    }

    int GetSum(int qStart, int qEnd) {
        return getSum(0, 0, this->arrSize - 1, qStart, qEnd);
    }

    void PrintSegmentTree() {
        for (int i = 0; i < this->N; i++)
            std::cout << this->tree[i] << ", ";
        std::cout << std::endl;
    }
};

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr, sizeof(arr) / sizeof(arr[0]));
    st.PrintSegmentTree();

    return 0;
}
