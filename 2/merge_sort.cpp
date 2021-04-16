#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vc, int a, int b, int c)
{
    vector<int> left, right;

    for (int i = a; i <= b; i++)
    {
        left.push_back(vc[i]);
    }

    for (int i = b + 1; i <= c; i++)
    {
        right.push_back(vc[i]);
    }

    // 哨兵标志 INT_MAX
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);

    int l = 0, r = 0;

    for (int i = a; i < c + 1; i++)
    {
        if (left[l] < right[r])
        {
            vc[i] = left[l];
            ++l;
        }
        else
        {
            vc[i] = right[r];
            ++r;
        }
    }
}

void inner_merge_sort(vector<int> &vc, int m, int n)
{
    if (m < n)
    {
        int q = m + (n - m) / 2;

        inner_merge_sort(vc, m, q);
        inner_merge_sort(vc, q + 1, n);

        merge(vc, m, q, n);
    }
}

void merge_sort(vector<int> &vc)
{
    auto size = vc.size();

    inner_merge_sort(vc, 0, size - 1);
}

int main()
{
    vector<int> vc = {5,
                      7,
                      3,
                      19,
                      10,
                      6,
                      10};

    merge_sort(vc);

    for (auto i : vc)
    {
        cout << i << endl;
    }

    return 0;
}