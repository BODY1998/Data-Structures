#include <iostream>
using namespace std;
// stack using array
class Stack
{
private:
    // attributes
    int top, size, *arr;

public:
    // constructor
    Stack(int size)
    {
        arr = new int[size];
        size = size;
        // top is pointing to next element in the stack
        top = 0;
    }
    // fundamental methods
    void push(int element)
    {
        // first check if stack is full
        if (top >= size)
        {
            cout << "stack is full and will be doubled" << endl;
            double_size();
        }
        else
        {
            arr[top] = element;
            top++;
        }
    }
    int pop()
    {
        // first check if stack is empty
        if (top == 0)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            // return deleted element
            top--;
            return arr[top];
        }
    }
    int get_top()
    {
        if (top == 0)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
            // returning the last element which its index will be top - 1
            return arr[top - 1];
    }
    int get_size()
    {
        return size;
    }
    int get_num_of_elements()
    {
        return top;
    }
    bool isFull()
    {
        return top >= size;
    }
    bool isEmpty()
    {
        return top == 0;
    }
    void double_size()
    {
        int *temparr;
        temparr = new int[size * 2];
        for (int i = 0; i < top; i++)
        {
            temparr[i] = arr[i];
        }
        delete arr;
        size = size * 2;
        arr = temparr;
    }
    void delete_stack()
    {
        top = 0;
    }
    void print_stack()
    {
        if (top == 0)
            cout << "stack is empty" << endl;
        else
        {
            for (int i = 0; i < top; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack myStack(10);
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    cout << myStack.get_top() << endl;
    cout << myStack.get_num_of_elements() << endl;
    cout << myStack.isFull() << endl;
    myStack.print_stack();
    cout << myStack.pop() << endl;
    myStack.print_stack();
    return 0;
}