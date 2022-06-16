int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> meet;

    for (int i = 0; i < n; i++)
    {
        meet.push_back({end[i], start[i]});
    }

    sort(meet.begin(), meet.end());

    int last = meet[0].first;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        if (meet[i].second > last)
        {
            ans++;
            last = meet[i].first;
        }
    }
    return ans;
}