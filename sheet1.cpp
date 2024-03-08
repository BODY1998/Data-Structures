#include <iostream>
#include <ctime>
using namespace std;

class Sorting
{

private:
    int n;
    int *arr;

public:
    Sorting(int size)
    {
        n = size;
        arr = new int[size];
    }
    void read()
    {

        for (int i = 0; i < n; i++)
        {
            *(arr + i) = i + 2;
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << *(arr + i) << "\t";
        }
    }

    // An optimized version of Bubble Sort
    // void bubbleSort(int arr[], int n)
    void bubble()
    {
        int i, j, temp;
        bool swapped;
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                } // if
            }     // nested for

            // If no two elements were swapped
            // by inner loop, then break
            if (swapped == false)
                break;
        }
    }

    // Function for Selection sort
    void selection()
    {
        int i, j, min_idx, temp;

        // One by one move boundary of
        // unsorted subarray
        for (i = 0; i < n - 1; i++)
        {

            // Find the minimum element in
            // unsorted array
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }

            // Swap the found minimum element
            // with the first element
            if (min_idx != i)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Function to sort an array using
    // insertion sort
    void insertion()
    {
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            // Move elements of arr[0..i-1],
            // that are greater than key,
            // to one position ahead of their
            // current position
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

// Driver program to test above functions
int main(int argc, char **argv)
{

    Sorting obj(100);
    obj.read();
    cout << "\ncontent of array before sort\n";
    obj.print();
    time_t now1 = time(0);
    obj.bubble();
    time_t now2 = time(0);
    cout << "\nbubble sort time =" << now1;
    cout << "\nbubble sort time =" << now2;
    now1 = time(0);
    obj.insertion();
    now2 = time(0);
    cout << "\ninsertion sort time =" << now2 - now1;
    cout << "\ncontent of array after sort\n";
    obj.print();
    now1 = time(0);
    obj.selection();
    now2 = time(0);
    cout << "/selection sort time =" << now2 - now1;
    cout << "/ncontent of array after sort\n";

    return 0;
}