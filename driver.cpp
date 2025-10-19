#include "ArrayQueue.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
    ArrayQueue<string> myQueue(5);

    cout << "   TESTING ENQUEUE" << endl;
    cout << "*--------------------*" << endl;
    cout << "Length of empty myQueue: " << myQueue.getLength() << endl;
    cout << "Checking using the 'isEmpty' method: ";
    if (myQueue.isEmpty()) {
        cout << "The queue is empty. " << endl;
    }
    else {
        cout << "The queue is not empty. " << endl;
    }

    myQueue.enqueue("Wow");
    myQueue.enqueue("Amazing");
    cout << "Length of myQueue after enqueuing two strings: " << myQueue.getLength() << endl;
    cout << "Front element: " << myQueue.front() << endl;
    cout << "Back element: " << myQueue.back() << endl;
    cout << endl;
    cout << endl;

    cout << "   TESTING DEQUEUE" << endl;
    cout << "*--------------------*" << endl;
    cout << "Removing one element from myQueue. " << endl;
    myQueue.dequeue();
    cout << "Front element after one dequeue: " << myQueue.front() << endl;
    cout << "Length of myQueue: " << myQueue.getLength() << endl;
    cout << "   *----*" << endl;
    cout << "Dequeuing remaining element. " << endl;
    myQueue.dequeue();
    cout << "Checking if myQueue is empty now: ";
    if (myQueue.isEmpty()) {
        cout << "The queue is empty. " << endl;
    }
    else {
        cout << "The queue is not empty. " << endl;
    }
    cout << "Trying to dequeue from an empty queue. " << endl;
    try {
        myQueue.dequeue();
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << endl;
    cout << endl;

    cout << "   TESTING QUEUE" << endl;
    cout << "*--------------------*" << endl;
    cout << "Filling the queue completely. " << endl;
    myQueue.enqueue("A");
    myQueue.enqueue("B");
    myQueue.enqueue("C");
    myQueue.enqueue("D");
    myQueue.enqueue("E");
    cout << "Checking if myQueue is full: ";
    if (myQueue.isFull()) {
        cout << "The queue is full. " << endl;
    }
    else {
        cout << "The queue is not full. " << endl;
    }
    cout << "Trying to enqueue another element (should throw error). " << endl;
    try {
        myQueue.enqueue("F");
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << "   *----*" << endl;
    cout << "Dequeuing two elements. " << endl;
    myQueue.dequeue();
    myQueue.dequeue();
    cout << "Enqueuing two more elements (wrap-around). " << endl;
    myQueue.enqueue("X");
    myQueue.enqueue("Y");
    cout << "Front element: " << myQueue.front() << endl;
    cout << "Back element: " << myQueue.back() << endl;
    cout << "Length of myQueue: " << myQueue.getLength() << endl;
    cout << endl;
    cout << endl;

    cout << "   TESTING DEEP COPY" << endl;
    cout << "*--------------------*" << endl;
    cout << "Copying myQueue using the overloaded = assignment operator." << endl;
    ArrayQueue<string> copyQueue(5);
    copyQueue = myQueue;
    cout << "Dequeuing one element from copyQueue to ensure deep copy. " << endl;
    copyQueue.dequeue();
    cout << "Length of copyQueue: " << copyQueue.getLength() << endl;
    cout << "Length of myQueue: " << myQueue.getLength() << endl;
    cout << "   *----*" << endl;
    cout << "Copying myQueue using the copy constructor. " << endl;
    ArrayQueue<string> copyQueueTwo(myQueue);
    cout << "Dequeuing one element from copyQueueTwo to check deep copy. " << endl;
    copyQueueTwo.dequeue();
    cout << "Length of copyQueueTwo: " << copyQueueTwo.getLength() << endl;
    cout << "Length of myQueue: " << myQueue.getLength() << endl;
    cout << endl;
    cout << endl;

    cout << "   TESTING CLEAR" << endl;
    cout << "*--------------------*" << endl;
    cout << "Clearing contents of myQueue. " << endl;
    myQueue.clear();
    cout << "Length of myQueue after clear: " << myQueue.getLength() << endl;
    cout << "Checking using the 'isEmpty' method: ";
    if (myQueue.isEmpty()) {
        cout << "The queue is empty. " << endl;
    }
    else {
        cout << "The queue is not empty. " << endl;
    }
    cout << endl;
    cout << endl;

    cout << "   OTHER DATATYPE" << endl;
    cout << "*--------------------*" << endl;
    ArrayQueue<int> intQueue(3);
    intQueue.enqueue(1000);
    intQueue.enqueue(2000);
    cout << "Front of intQueue: " << intQueue.front() << endl;
    cout << "Back of intQueue: " << intQueue.back() << endl;
    cout << "   *----*" << endl;
    cout << "Dequeuing an element from intQueue. " << endl;
    intQueue.dequeue();
    cout << "Front of intQueue: " << intQueue.front() << endl;
    cout << "   *----*" << endl;
    cout << "Copying intQueue using the copy constructor. " << endl;
    ArrayQueue<int> copyIntQueue(intQueue);
    cout << "Dequeuing an element from copyIntQueue to ensure deep copy. " << endl;
    copyIntQueue.dequeue();
    cout << "Length of copyIntQueue: " << copyIntQueue.getLength() << endl;
    cout << "Length of intQueue: " << intQueue.getLength() << endl;
    cout << endl;
}
