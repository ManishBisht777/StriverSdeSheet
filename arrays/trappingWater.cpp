// better sol

int trap(vector<int> &height)
{

    int n = height.size();

    int prefix[n], suffix[n];

    prefix[0] = height[0];
    suffix[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], height[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += min(prefix[i], suffix[i]) - height[i];
    }

    return ans;
}

// optimised sol
int trap(vector<int> &A)
{

    int n = A.size();

    int left = 0;
    int right = n - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while (left <= right)
    {
        if (A[left] <= A[right])
        {
            if (A[left] >= maxleft)
                maxleft = A[left];
            else
                res += maxleft - A[left];
            left++;
        }
        else
        {
            if (A[right] >= maxright)
                maxright = A[right];
            else
                res += maxright - A[right];
            right--;
        }
    }
    return res;
}