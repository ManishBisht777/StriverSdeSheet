bool static comparison(Job j1, Job j2)
{
    return (j1.profit > j2.profit);
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, comparison);

    int maxi = arr[0].dead;

    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].dead);
    }

    vector<int> help(maxi + 1, -1);

    int jobs = 0, profit = 0;

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = arr[i].dead; j >= 1; j--)
        {
            if (help[j] == -1)
            {
                help[j] = i;
                jobs++;
                profit += arr[i].profit;
                break;
            }
        }
    }

    return {jobs, profit};
}