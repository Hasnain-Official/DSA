#include <iostream>
#include <stdexcept>

class NStacks {
private:
    int *arr;      // Array to store stack elements
    int *top;      // Array to store indices of top elements of stacks
    int *next;     // Array to store next entry in all stacks and free list
    int free;      // To store the beginning index of the free list
    int numStacks; // Number of stacks
    int size;      // Total size of the array

public:
    NStacks(int numStacks, int size) {
        this->numStacks = numStacks;
        this->size = size;
        arr = new int[size];
        top = new int[numStacks];
        next = new int[size];

        // Initialize all stacks as empty
        for (int i = 0; i < numStacks; ++i) {
            top[i] = -1;
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

    // Check if a specific stack is empty
    bool isEmpty(int stackNum) {
        return top[stackNum] == -1;
    }

    // Push an element to a specific stack
    void push(int stackNum, int value) {
        if (isFull()) {
            throw std::overflow_error("Stack Overflow");
        }

        int i = free;         // Get the first free index
        free = next[i];       // Update free to index of the next slot

        next[i] = top[stackNum]; // Link the new element to the previous top element
        top[stackNum] = i;       // Update the top to the new element
        arr[i] = value;          // Add the element to the array
    }

    // Pop an element from a specific stack
    int pop(int stackNum) {
        if (isEmpty(stackNum)) {
            throw std::underflow_error("Stack Underflow");
        }

        int i = top[stackNum];    // Get the top element index
        top[stackNum] = next[i];  // Update top to the next element in the stack
        next[i] = free;           // Add the popped index to the free list
        free = i;                 // Update free to the popped index

        return arr[i];            // Return the popped element
    }

    // Get the top element of a specific stack
    int peek(int stackNum) {
        if (isEmpty(stackNum)) {
            throw std::underflow_error("Stack is Empty");
        }
        return arr[top[stackNum]];
    }

    ~NStacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    int numStacks = 3, size = 10;
    NStacks stacks(numStacks, size);

    stacks.push(0, 15);
    stacks.push(1, 45);
    stacks.push(2, 30);

    std::cout << "Top element of stack 0: " << stacks.peek(0) << std::endl;
    std::cout << "Top element of stack 1: " << stacks.peek(1) << std::endl;
    std::cout << "Top element of stack 2: " << stacks.peek(2) << std::endl;

    stacks.pop(1);
    std::cout << "Top element of stack 1 after pop: " << stacks.peek(1) << std::endl;

    return 0;
}
