int findPlatform(int arr[], int dept[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dept, dept + n);

    int maxi = 1;
    int ans = 1;

    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (arr[i] <= dept[j])
        {
            maxi++;
            i++;
        }
        else
        {
            maxi--;
            j++;
        }
        ans = max(maxi, ans);
    }
    return ans;
}