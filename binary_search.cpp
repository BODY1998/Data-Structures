#include <iostream>
using namespace std;

// binary search
int binary_search(int *arr, int size, int num)
{
    int first = 0;
    int last = size - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (num == arr[mid])
        {
            return mid;
        }
        if (num > arr[mid])
        {
            first = mid + 1;
        }
        else
            last = mid - 1;
    }
    return -1;
}

// generate array with sorted random numbers
void generate_sorted_random_numbers(int *arr, int size, int max)
{
    srand(time(NULL));
    arr[0] = rand() % max;
    for (int k = 1; k < size; k++)
    {
        arr[k] = arr[k - 1] + rand() % max;
    }
}

int main()
{
    int *arr, size, num, index;
    cout << "Please enter size of array" << endl;
    cin >> size;
    arr = new int[size];
    generate_sorted_random_numbers(arr, size, 20);
    // printing sorted rand array
    cout << "sorted rand array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    // read number from user
    cout << "Please enter number" << endl;
    cin >> num;
    // searching
    index = binary_search(arr, size, num);
    if (index == -1)
        cout << "number not found " << endl;

    else
        cout << "number found at index : " << index << endl;
    return 0;
}