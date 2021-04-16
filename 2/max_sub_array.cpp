#include <iostream>
#include <vector>

using namespace std;

// 动态规划法？贪心算法？
int max_sub_array_1(vector<int> &nums)
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

int find_mid_max_sub_array(vector<int> &nums, int low, int mid, int hight)
{
    int left_sum = 0;
    int left_max = INT_MIN;
    int l = mid;

    while (l > low - 1)
    {
        left_sum += nums[l];
        if (left_max < left_sum)
        {
            left_max = left_sum;
        }
        --l;
    }

    int right_sum = 0;
    int right_max = INT_MIN;
    int r = mid + 1;

    while (r < hight + 1)
    {
        right_sum += nums[r];
        if (right_max < right_sum)
        {
            right_max = right_sum;
        }
        r++;
    }

    return left_max + right_max;
}

// 分治法（Divide-and-Conquer）
int max_sub_array_2(vector<int> &nums, int low, int hight)
{
    if (low == hight)
    {
        return nums[low];
    }

    int mid = low + (hight - low) / 2;

    int left_max = max_sub_array_2(nums, low, mid);
    int right_max = max_sub_array_2(nums, mid + 1, hight);
    int mid_max = find_mid_max_sub_array(nums, low, mid, hight);

    return max(max(left_max, right_max), mid_max);
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
        << max_sub_array_1(nums) << endl;

    cout
        << max_sub_array_2(nums, 0, nums.size() - 1) << endl;

    return 0;
}