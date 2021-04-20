#include <iostream>

using namespace std;

// 维持最大堆
void max_heapify(int a[], int i, int heap_size)
{
    int largest = i;
    int left = 2 * largest + 1;
    int right = 2 * largest + 2;

    // 防止越界
    if (left < heap_size && a[left] > a[i])
    {
        largest = left;
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

        max_heapify(a, largest, heap_size);
    }
}

// 维持最大堆，非递归版
void max_heapify_2(int a[], int i, int heap_size)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap_size && a[left] > a[i])
        {
            largest = left;
        }

        if (right < heap_size && a[right] > a[largest])
        {
            largest = right;
        }

        if (largest == i)
            return;

        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        i = largest;
    }
}

// 构建最大堆
void build_max_heap(int a[], int l)
{
    for (int i = l / 2 - 1; i >= 0; i--)
    {
        max_heapify(a, i, l);
    }
}

// 堆排序
void heap_sort(int a[], int l)
{
    int heap_size = l;

    build_max_heap(a, heap_size);

    for (int i = heap_size - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        --heap_size;

        max_heapify(a, 0, heap_size);
    }
}

int main()
{
    int a[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int heap_size = 10;

    heap_sort(a, heap_size);

    for (auto i : a)
    {
        cout << i << endl;
    }

    return 0;
}