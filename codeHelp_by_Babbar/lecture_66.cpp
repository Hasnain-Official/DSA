// NQueueInAnArray

/*
    Enqueue Operation: O(1)
    Dequeue Operation: O(1)
    Space Complexity: O(n), where n is the size of the array used to store the values.
 */

#include <iostream>
#include <stdexcept>
#include <vector>

class NQueues {
private:
    int *arr;       // Array to store queue elements
    int *front;     // Array to store the front indices of the queues
    int *rear;      // Array to store the rear indices of the queues
    int *next;      // Array to store the next entry in all queues and the free list
    int free;       // To store the beginning index of the free list
    int numQueues;  // Number of queues
    int size;       // Total size of the array

public:
    NQueues(int numQueues, int size) {
        this->numQueues = numQueues;
        this->size = size;
        arr = new int[size];
        front = new int[numQueues];
        rear = new int[numQueues];
        next = new int[size];

        // Initialize all queues as empty
        for (int i = 0; i < numQueues; ++i) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize all spaces as free
        free = 0;
        for (int i = 0; i < size - 1; ++i) {
            next[i] = i + 1;
        }
        next[size - 1] = -1; // -1 indicates the end of the free list
    }

    // Check if the array is full
    bool isFull() {
        return free == -1;
    }

    // Check if a specific queue is empty
    bool isEmpty(int queueNum) {
        return front[queueNum] == -1;
    }

    // Enqueue an element to a specific queue
    void enqueue(int queueNum, int value) {
        if (isFull()) {
            throw std::overflow_error("Queue Overflow");
        }

        int i = free;          // Get the first free index
        free = next[i];        // Update free to index of the next slot

        if (isEmpty(queueNum)) {
            front[queueNum] = i; // If the queue is empty, update front
        } else {
            next[rear[queueNum]] = i; // Link the new element to the previous rear element
        }

        next[i] = -1;          // Indicate the end of the queue
        rear[queueNum] = i;    // Update rear to the new element
        arr[i] = value;        // Add the element to the array
    }

    // Dequeue an element from a specific queue
    int dequeue(int queueNum) {
        if (isEmpty(queueNum)) {
            throw std::underflow_error("Queue Underflow");
        }

        int i = front[queueNum]; // Get the front element index
        front[queueNum] = next[i]; // Update front to the next element in the queue

        if (front[queueNum] == -1) {
            rear[queueNum] = -1; // If the queue becomes empty, update rear
        }

        next[i] = free;        // Add the dequeued index to the free list
        free = i;              // Update free to the dequeued index

        return arr[i];         // Return the dequeued element
    }

    ~NQueues() {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main() {
    int numQueues = 3, size = 10;
    NQueues queues(numQueues, size);

    queues.enqueue(0, 15);
    queues.enqueue(1, 45);
    queues.enqueue(2, 30);
    queues.enqueue(0, 25);
    queues.enqueue(1, 55);
    queues.enqueue(2, 35);

    std::cout << "Dequeue from queue 0: " << queues.dequeue(0) << std::endl;
    std::cout << "Dequeue from queue 1: " << queues.dequeue(1) << std::endl;
    std::cout << "Dequeue from queue 2: " << queues.dequeue(2) << std::endl;

    return 0;
}
