#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, *arr, counter, size;

public:
    Queue(int size)
    {
        size = size;
        arr = new int[size];
        front = rear = counter = 0;
    }
    void enquque(int element)
    {
        arr[rear] = element;
        rear = (rear + 1) % size;
        counter++;
    }
    int dequeue()
    {
        int tempFront = front;
        front = (front + 1) % size;
        counter--;
        return arr[tempFront];
    }
    int get_num_of_elements()
    {
        return counter;
    }
    bool isFull()
    {
        return counter == size;
    }
    bool isEmpty()
    {
        return counter == 0;
    }
    void double_size()
    {
        int *tempArr = new int[size * 2];
        for (int i = 0; i < size; i++)
        {
            tempArr[i] = arr[(i + front) % size];
        }
        size = size * 2;
        delete arr;
        arr = tempArr;
        front = 0;      // reset front in the new array
        rear = counter; // makes rear ready to the new element
    }
};