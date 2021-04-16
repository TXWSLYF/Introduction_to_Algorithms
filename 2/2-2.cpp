#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int> &vc, bool asc = true)
{
    auto size = vc.size();

    for (int j = 0; j < size; j++)
    {
        int key = j;

        for (int i = j + 1; i < size; i++)
        {
            if (asc ? vc[i] < vc[key] : vc[i] > vc[key])
            {
                key = i;
            }
        }

        int temp = vc[j];
        vc[j] = vc[key];
        vc[key] = temp;
    }
}

int main()
{
    vector<int> vc = {10,
                      3,
                      1,
                      2,
                      8};
    select_sort(vc);

    for (auto i : vc)
    {
        cout << i << endl;
    }

    return 0;
}