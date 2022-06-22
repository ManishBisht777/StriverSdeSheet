double multiply(double m, int n)
{
    double ans = 1.00;
    while (n > 0)
    {
        ans *= m;
        n--;
    }
    return ans;
}

double findNthRootOfM(int n, long long m)
{
    // Write your code here.
    double l = 1, r = m, esp = 1e-8;
    while ((r - l) > esp)
    {
        double mid = (l + r) / 2.00;
        if (multiply(mid, n) < (double)m)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}