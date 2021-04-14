#include <iostream>
#include <vector>

using namespace std;

// 插入排序-升序-非最优
void insertion_sort_asc_bad(vector<int> &un_sort_arr)
{
    auto size = un_sort_arr.size();

    for (int i = 1; i < size; i++)
    {

        for (int j = 0; j < i; j++)
        {
            if (un_sort_arr[j] > un_sort_arr[i])
            {
                int temp = un_sort_arr[i];
                int diff = i - j;

                // 多了一层循环
                while (diff)
                {
                    un_sort_arr[j + diff] = un_sort_arr[j + diff - 1];
                    --diff;
                }

                un_sort_arr[j] = temp;
                break;
            }
        }
    }
}

// 插入排序-升序
void insertion_sort_asc(vector<int> &un_sort_arr)
{
    for (int j = 1; j < un_sort_arr.size(); j++)
    {
        int key = un_sort_arr[j];
        int i = j - 1;

        while (i >= 0 && un_sort_arr[i] > key)
        {
            un_sort_arr[i + 1] = un_sort_arr[i];
            --i;
        }

        un_sort_arr[i + 1] = key;
    }
}

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

    insertion_sort_asc(un_sort_arr);
    insertion_sort_desc(un_sort_arr);

    for (auto i : un_sort_arr)
    {
        cout << i << endl;
    }

    return 0;
}