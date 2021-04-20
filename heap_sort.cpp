#include <iostream>

using namespace std;

void max_heapify(int a[], int i, int heap_size)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;

    if (left < heap_size && a[left] > a[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right < heap_size && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        max_heapify(a, largest);
    }
}

void heap_sort(int a[], int l)
{
    max_heapify(a, 0, l);
}

int main()
{
    int a[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int heap_size = 10;

    heap_sort(a, 10);

    for (auto i : a)
    {
        cout << i << endl;
    }

    return 0;
}