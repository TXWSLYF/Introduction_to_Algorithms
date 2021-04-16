#include <iostream>
#include <vector>

using namespace std;

int max_sub_array(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int current_sum = 0;
    int best_sum = INT_MIN;

    for (auto i : nums)
    {
        current_sum = max(i, current_sum + i);
        best_sum = max(best_sum, current_sum);
    }

    return best_sum;
}

int main()
{
    vector<int> nums = {-2,
                        1,
                        -3,
                        4,
                        -1,
                        2,
                        1,
                        -5,
                        4};

    cout
        << max_sub_array(nums) << endl;

    return 0;
}