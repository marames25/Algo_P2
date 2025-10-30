#include <bits/stdc++.h>
using namespace std;

class MAxHeap{
    vector<int> heap;
    // max Heap
    void heapifyDown(int i){
        int left = 2*i+1, 
        right = 2*i+2,
        largest = i;
        if(left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if(right < heap.size() && heap[right] > heap[largest])
            largest = right;
        if(largest != i){
            swap(heap[i],heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i){
        if(i==0)
            return;
        int parent = (i-1)/2;
        if(heap[parent]<heap[i]){
            swap(heap[parent],heap[i]);
            heapifyUp(parent);
        }
    }

public:
    void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    int getMax(){
        if(heap.empty()){
            cout<<" NO ELEMENTS!!"<<endl;
            return -1;
        }

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty())
            heapifyDown(0);
        
        return maxVal;

    }

    bool empty() const {
         return heap.empty(); 
    }
    void displayMaxHeap() const {
        for (int v : heap)
            cout << v << " ";
        cout << endl;
    }
};

class MinHeap{
    vector<int> heap;
    // min Heap
    void heapifyDown(int i){
        int left = 2*i+1, 
        right = 2*i+2,
        smallest = i;
        if(left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if(right < heap.size() && heap[right] < heap[smallest])
            smallest = right ;
        if(smallest != i){
            swap(heap[i],heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i){
        if(i==0)
            return;
        int parent = (i-1)/2;
        if(heap[parent] > heap[i]){
            swap(heap[parent],heap[i]);
            heapifyUp(parent);
        }
    }
public:
    void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    int getMin(){
        if(heap.empty()){
            cout<<" NO ELEMENTS!!"<<endl;
            return -1;
        }

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty())
            heapifyDown(0);
        
        return minVal;

    }
    bool empty() const {
         return heap.empty(); 
    }

    void displayMinHeap() const {
        for (int v : heap)
            cout << v << " ";
        cout << endl;
    }
};

class PQ{
    // higher priority
    MAxHeap pq;

public:
    void push(int val){
        pq.insert(val);
    }
    int pop(){
        return pq.getMax();
    }
    void display() const {
         pq.displayMaxHeap(); 
    }

    bool empty() const {
         return pq.empty();
    }
};

void heapSort(vector<int>& arr) {
    MAxHeap h;
    // build max heap from array
    for (int v : arr)
        h.insert(v);
    // repeatedly extract max and store in reverse order
    for (int i = arr.size() - 1; i >= 0; i--)
        arr[i] = h.getMax();
}
int main() {
    cout << "----------- MAX HEAP -----------" << endl;
    MAxHeap maxH;
    maxH.insert(10);
    maxH.insert(30);
    maxH.insert(20);
    maxH.insert(50);
    cout << "Max Heap elements: ";
    maxH.displayMaxHeap();

    cout << "Extracted Max: " << maxH.getMax() << endl;
    cout << "After extraction: ";
    maxH.displayMaxHeap();


    cout << "\n----------- MIN HEAP -----------" << endl;
    MinHeap minH;
    minH.insert(10);
    minH.insert(30);
    minH.insert(20);
    minH.insert(5);
    cout << "Min Heap elements: "; 
    minH.displayMinHeap();

    cout << "Extracted Min: " << minH.getMin() << endl;
    cout << "After extraction: ";
    minH.displayMinHeap();


    cout << "\n----------- PRIORITY QUEUE -----------" << endl;
    PQ pq;
    pq.push(15);
    pq.push(40);
    pq.push(5);
    pq.push(25);
    cout << "Priority Queue contents: ";
    pq.display();

    cout << "Highest priority (pop): " << pq.pop() << endl;
    cout << "After pop: ";
    pq.display();


    cout << "\n----------- HEAP SORT -----------" << endl;
    vector<int> arr = {4, 1, 7, 3, 8, 5};
    cout << "Original array: ";
    for (int v : arr) cout << v << " ";
    cout << endl;

    heapSort(arr);
    cout << "Sorted array: ";
    for (int v : arr) cout << v << " ";
    cout << endl;

    return 0;
}
