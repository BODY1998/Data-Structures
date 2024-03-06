#include <iostream>
using namespace std;
// bubble sort

void bubble_sort(int *arr, int size)
{
    // number of turns
    for (int i = 0; i < size - 1; i++)
    {
        // number of comparison operations
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    srand(time(0));
    int *arr, size;
    cout << "Please enter size of array" << endl;
    cin >> size;
    arr = new int[size];
    // fill array with rand nums
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20;
    }
    // printing array before sorting
    cout << "array before sorting" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    // sorting ...
    bubble_sort(arr, size);
    // printing array after sorting
    cout << "array after sorting" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}