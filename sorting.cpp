#include <iostream>
using namespace std;

// bubble sort
void bubble_sort(int *arr, int size)
{
    int a, b, temp, flag;
    b = 1;
    do
    {
        flag = 0;
        for (a = 0; a < size - b; a++)
        {
            if (arr[a] > arr[a + 1])
            {
                temp = arr[a];
                arr[a] = arr[a + 1];
                arr[a + 1] = temp;
                flag++;
            }
        }
        b++;
    } while (flag > 0);
}

// selection sort
void selection_sort(int *arr, int size)
{
    int a, b, minloc, temp;
    for (a = 0; a <= size - 2; a++)
    {
        minloc = a;
        for (b = a + 1; b <= size - 1; b++)
            if (arr[b] < arr[minloc])
                minloc = b;
        temp = arr[a];
        arr[a] = arr[minloc];
        arr[minloc] = temp;
    }
}

// insertion sort
void insertion_sort(int *arr, int size)
{
    int a, b, temp;
    for (a = 1; a <= size - 1; a++)
    {
        temp = arr[a];
        for (b = a - 1; b >= 0; b--)
            if (temp < arr[b])
                arr[b + 1] = arr[b];
            else
                break;
        arr[b + 1] = temp;
    }
}

int main()
{
    srand(time(0));
    int *array, size;
    cout << "Please enter size of array" << endl;
    cin >> size;
    array = new int[size];
    // fill array with rand nums
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 20;
    }
    // printing array before sorting
    cout << "array before sorting" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }
    // sorting ...
    insertion_sort(array, size);
    // printing array after sorting
    cout << "array after sorting" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}