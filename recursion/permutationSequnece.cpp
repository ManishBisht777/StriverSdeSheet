// my approach

void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

string getPermutation(int n, int k)
{

    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }

    int idx = 0;
    while (idx++ < k - 1)
    {
        nextPermutation(nums);
    }

    string ans = "";
    for (auto it : nums)
    {
        ans += to_string(it);
    }

    return ans;
}

// mast approach

string getPermutation(int n, int k)
{

    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        nums.push_back(i);
    }

    nums.push_back(n);
    k -= 1;

    string ans = "";
    while (true)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);

        if (nums.size() == 0)
            break;

        k = k % fact;
        fact = fact / nums.size();
    }

    return ans;
}