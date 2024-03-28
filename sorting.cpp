#include <iostream>
using namespace std;

// bubble sort
void bubble_sort(int *arr, int size)
{
    int bubble, flag;
    bubble = 1;
    do
    {
        flag = 0;
        // comparison loop
        for (int i = 0; i < size - bubble; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                // swap
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag++;
            }
        }
        bubble++;
    } while (flag > 0);
}

// selection sort
void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minimum = i;
        for (int k = i + 1; k < size; k++)
        {
            if (arr[k] < arr[minimum])
                minimum = k;
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}

// insertion sort
void insertion_sort(int *arr, int size)
{
    // assume first element is ordered already
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int k;
        for (k = i - 1; k >= 0; k--)
        {
            if (temp < arr[k])
                arr[k + 1] = arr[k];
            else
                break;
        }
        arr[k + 1] = temp;
    }
}

// merge two lists
void merge_two_lists(int *arr, int f1, int e1, int f2, int e2)
{
    int *tempArr = new int[e2 - f1 + 1];
    int k1 = f1, k2 = f2, k3 = 0;
    while ((k1 <= e1) && (k2 <= e2))
    {
        if (arr[k1] < arr[k2])
        {
            tempArr[k3] = arr[k1];
            k3++;
            k1++;
        }
        else
        {
            tempArr[k3] = arr[k2];
            k3++;
            k2++;
        }
    }
    while (k1 <= e1)
    {
        tempArr[k3] = arr[k1];
        k3++;
        k1++;
    }
    while (k2 <= e2)
    {
        tempArr[k3] = arr[k2];
        k3++;
        k2++;
    }

    for (int i = 0; i <= e2 - f1; i++)
        arr[i + f1] = tempArr[i];
}

// merge sort
void merge_sort(int *arr, int first, int last)
{
    int mid;
    if (first == last) // base case
        return;
    else
        mid = (first + last) / 2; // logic
    merge_sort(arr, first, mid);
    merge_sort(arr, mid + 1, last);
    merge_two_lists(arr, first, mid, mid + 1, last);
}

// quick sort
void quick_sort(int *arr, int first, int last)
{
    int L = first + 1, R = last;
    if (first >= last)
        return;
    int pivot = arr[first];
    while (L <= R)
    {
        while ((L <= last) && (arr[L] <= pivot))
            L++;
        while ((R > first) && (arr[R] >= pivot))
            R--;
        if (L < R)
        {
            int temp = arr[L];
            arr[L] = arr[R];
            arr[R] = temp;
        }
    }

    arr[first] = arr[R];
    arr[R] = pivot;
    quick_sort(arr, first, R - 1);
    quick_sort(arr, R + 1, last);
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
    merge_sort(array, 0, size);
    // printing array after sorting
    cout << "array after sorting" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }
    return 0;
}