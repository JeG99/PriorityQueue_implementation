#include <vector>

class PriorityQueue {
public:
	PriorityQueue();
	PriorityQueue(bool p);

	int size();
	bool empty();
	int top();
	
	void pop();
	void push(int data);

private:
	bool priority;
	int length;
	std::vector<int> heap;

	void swap(int &a, int &b);
	void onDemandHeapify(int i);
	void heapify(int i);

};

PriorityQueue::PriorityQueue() {
	length = 0;
	heap.push_back(-1000);
}

PriorityQueue::PriorityQueue(bool p) {
	length = 0;
	heap.push_back(-1000);
	priority = p;
}

int PriorityQueue::size() {
	return length;
}

bool PriorityQueue::empty() {
	return (length == 0);
}

int PriorityQueue::top() {
	return heap[1];
}

void PriorityQueue::swap(int &a, int &b){
	int aux = a;
	a = b;
	b = aux;
}

void PriorityQueue::onDemandHeapify(int i){
	while(i > 1){
		if(priority){
			if(heap[i] > heap[i/2]){
				swap(heap[i/2], heap[i]);
				i /= 2;
			}
			else{
				break;
			}
		}	
		else{
			if(heap[i] < heap[i/2]){
				swap(heap[i/2], heap[i]);
				i /= 2;
			}
			else{
				break;
			}
		}
	}
}

void PriorityQueue::push(int data){
	heap.push_back(data);
	length++;
	if(length > 1){
		onDemandHeapify(length);
	}
}

void PriorityQueue::pop() {
	if(length == 1){
		heap.erase(heap.begin());
		length--;
	}
	else{
		swap(heap[1], heap[length]);		
		heap.erase(heap.begin() + length);
		length--;
		heapify(1);
	}
}

void PriorityQueue::heapify(int k){
	while(true){
		if(priority){
			int leftChild = 2*k, rightChild = 2*k + 1;
			int bigger = k;
			if(leftChild < length && heap[leftChild] > heap[k]){
				bigger = leftChild;
			}
			if(rightChild < length && heap[rightChild] > heap[bigger]){
				bigger = rightChild;
			}
			if(bigger != k){
				swap(heap[bigger], heap[k]);
				k = bigger;
			}
			else{
				break;
			}
		}
		else{
			int leftChild = 2*k, rightChild = 2*k + 1;
			int smaller = k;
			if(leftChild < length && heap[leftChild] < heap[k]){
				smaller = leftChild;
			}
			if(rightChild < length && heap[rightChild] < heap[smaller]){
				smaller = rightChild;
			}
			if(smaller != k){
				swap(heap[smaller], heap[k]);
				k = smaller;
			}
			else{
				break;
			}	
		}
	}
}