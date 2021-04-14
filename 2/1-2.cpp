#include <iostream>
#include <vector>

using namespace std;

// 插入排序-降序
void insertion_sort_desc(vector<int> &un_sort_arr)
{
    for (int j = 1; j < un_sort_arr.size(); j++)
    {
        int key = un_sort_arr[j];
        int i = j - 1;

        // 仅仅改变了判断符号
        while (i >= 0 && un_sort_arr[i] < key)
        {
            un_sort_arr[i + 1] = un_sort_arr[i];
            --i;
        }

        un_sort_arr[i + 1] = key;
    }
}

int main()
{
    vector<int> un_sort_arr = {4, 2, 3, 1};

    insertion_sort_desc(un_sort_arr);

    for (auto i : un_sort_arr)
    {
        cout << i << endl;
    }

    return 0;
}