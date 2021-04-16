#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vc, int a, int b, int c)
{
    vector<int> left, right;

    for (int i = a; i < b + 1; i++)
    {
        left.push_back(vc[i]);
    }

    for (int i = b + 1; i < c + 1; i++)
    {
        right.push_back(vc[i]);
    }

    int l = 0, r = 0;

    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            vc[a + l + r] = left[l];
            ++l;
        }
        else
        {
            vc[a + l + r] = right[r];
            ++r;
        }
    }

    while (l < left.size())
    {
        vc[a + l + r] = left[l];
        ++l;
    }

    while (r < right.size())
    {
        vc[a + l + r] = right[r];
        ++r;
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
                      20,
                      11,
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