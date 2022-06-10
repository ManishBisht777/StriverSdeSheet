int merge(vector<int> &nums, int low, int mid, int high)
{
    int ans = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2LL * nums[j])
            j++;

        ans += (j - (mid + 1));
    }

    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }

    while (left <= mid)
        temp.push_back(nums[left++]);
    while (right <= high)
        temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }

    return ans;
}

int mergesort(vector<int> &nums, int l, int h)
{
    if (l >= h)
        return 0;
    int ans = 0;
    int mid = (l + h) / 2;

    ans += mergesort(nums, l, mid);
    ans += mergesort(nums, mid + 1, h);

    ans += merge(nums, l, mid, h);

    return ans;
}
int reversePairs(vector<int> &nums)
{
    return mergesort(nums, 0, nums.size() - 1);
}