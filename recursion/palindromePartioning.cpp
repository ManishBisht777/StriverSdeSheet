bool ispalindrome(string s, int st, int end)
{
    while (st <= end)
    {
        if (s[st++] != s[end--])
            return false;
    }

    return true;
}

void helper(vector<vector<string>> &ans, vector<string> &temp, string s, int partitionidx)
{
    if (partitionidx == s.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = partitionidx; i < s.size(); i++)
    {
        if (ispalindrome(s, partitionidx, i))
        {
            temp.push_back(s.substr(partitionidx, i - partitionidx + 1));
            helper(ans, temp, s, i + 1);

            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;

    helper(ans, temp, s, 0);

    return ans;
}