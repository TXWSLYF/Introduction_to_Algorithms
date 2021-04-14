#include <iostream>
#include <vector>

using namespace std;

int find_index(vector<int> &vc, int v)
{
    auto size = vc.size();

    for (int i = 0; i < size; i++)
    {
        if (vc[i] == v)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> vc = {1,
                      2,
                      5,
                      4,
                      5};
    cout << find_index(vc, 6) << endl;

    return 0;
}