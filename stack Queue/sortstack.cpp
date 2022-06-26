void sortchk(int a, stack<int> &s)
{
    if (!s.empty())
    {
        if (s.top() <= a)
        {
            s.push(a);
            return;
        }
    }
    if (s.empty())
    {
        s.push(a);
        return;
    }
    int x = s.top();
    s.pop();
    sortchk(a, s);
    s.push(x);
}
void SortedStack ::sort()
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    sort();
    sortchk(x, s);
}