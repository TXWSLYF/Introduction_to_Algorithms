#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &vc1, vector<int> &vc2)
{
    vector<int> vc_out;

    auto begin1 = vc1.begin();
    auto begin2 = vc2.begin();
    auto end1 = vc1.end();
    auto end2 = vc2.end();

    // 进位
    int a = 0;

    while ((begin1 != end1) && (begin2 != end2))
    {
        int temp = *begin1 + *begin2 + a;
        a = temp / 10;
        vc_out.push_back(temp % 10);

        ++begin1;
        ++begin2;
    }

    // 遍历 vc1 可能的剩余部分
    while (begin1 != end1)
    {
        int temp = *begin1 + a;
        a = temp / 10;
        vc_out.push_back(temp % 10);

        ++begin1;
    }

    // 遍历 vc2 可能的剩余部分
    while (begin2 != end2)
    {
        int temp = *begin2 + a;
        a = temp / 10;
        vc_out.push_back(temp % 10);
        ++begin2;
    }

    if (a)
    {
        vc_out.push_back(a);
    }

    return vc_out;
}

int main()
{
    vector<int> vc1 = {2, 9, 9, 7, 2};
    vector<int> vc2 = {9, 2, 9, 3};

    auto vc_out = add(vc1, vc2);

    for (auto i : vc_out)
    {
        cout << i << endl;
    }

    return 0;
}