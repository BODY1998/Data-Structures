#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, counter, size;

public:
    Queue(int *arr, int size)
    {
        arr = new int[size];
        front = 0;
        rear = size - 1;
        counter = 0;
    }
    bool isEmpty()
    {
        return counter == 0;
    }
    bool isFull()
    {
        return counter == size;
    }
    void enQueue(){
        
    }
};