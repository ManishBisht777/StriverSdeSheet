bool ispalindrome(string s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

string longestPalindrome(string s)
{

    if (s.size() == 0)
        return "";
    if (s.size() == 1)
        return s;

    string result = "";
    int n = s.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (ispalindrome(s.substr(i, j)))
            {
                if (result.size() < j)
                    result = s.substr(i, j);
            }
        }
    }

    return result;
}