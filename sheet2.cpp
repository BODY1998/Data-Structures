#include <iostream>
using namespace std;

class QueueType
{
public:
    QueueType()
    {
        size = 20;
        items = new char[size];
        front = rear = size - 1;
    }
    QueueType(int size)
    {
        items = new char[size];
        front = rear = size - 1;
    }

    void MakeEmpty()
    {
        front = rear = size - 1;
    }

    bool IsEmpty()
    {
        return (rear == front);
    }

    bool IsFull()
    {
        return ((rear + 1) % size == front);
    }

    void Enqueue(char newItem)
    {
        rear = (rear + 1) % size;
        items[rear] = newItem;
    }

    char Dequeue()
    {
        front = (front + 1) % size;
        int item = items[front];

        return (item);
    }

private:
    int front, rear;
    char *items;
    int size;
};
class StackType
{
public:
    StackType()
    {
        size = 20;
        items = new char[size];
        top = -1;
    }

    StackType(int size)
    {
        items = new char[size];
        top = -1;
    }

    void MakeEmpty()
    {
        top = -1;
    }

    bool IsEmpty()
    {
        return (top == -1);
    }

    bool IsFull()
    {
        return (top == size - 1);
    }

    void Push(char newItem)
    {
        top++;
        items[top] = newItem;
    }

    char Pop()
    {
        int item = items[top];
        top--;
        return (item);
    }

private:
    int top;
    char *items;
    int size;
};

int main()
{

    QueueType obj(40);
    StackType obj2(40);

    char phrase[] = "Able was I ere I saw Elba";
    int i = 0;
    char x = phrase[i];
    while (x != '\0')
    {
        obj.Enqueue(x);
        i++;
        x = phrase[i];
    }
    i = 0;
    x = phrase[i];
    while (x != '\0')
    {
        obj2.Push(x);
        i++;
        x = phrase[i];
    }

    cout << "elements in queue = ";
    while (!obj.IsEmpty())
    {

        cout << obj.Dequeue() << "\t";
    }
    cout << "\n";
    cout << "elements in stack = ";
    while (!obj2.IsEmpty())
    {

        cout << obj2.Pop() << "\t";
    }
}