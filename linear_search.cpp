#include <iostream>
using namespace std;

// linear search
int linear_search(int *arr, int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int *arr, size, num, index;
    // generate rand num array
    srand(time(0));
    cout << "Please enter size of array" << endl;
    cin >> size;
    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }

    // printing rand array
    cout << "rand array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    // read number from user
    cout << "Please enter number" << endl;
    cin >> num;

    // searching ...
    index = linear_search(arr, size, num);
    if (index < 0)
        cout << "number not found .." << endl;

    else
        cout << "number found at index : " << index << endl;

    return 0;
}