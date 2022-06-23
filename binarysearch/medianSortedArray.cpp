double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int n = nums1.size();
    int m = nums2.size();

    int m1 = -1, m2 = -1;

    int i = 0, j = 0;

    for (int cnt = 0; cnt <= (m + n) / 2; cnt++)
    {
        m2 = m1;

        if (i != n && j != m)
        {
            if (nums1[i] <= nums2[j])
            {
                m1 = nums1[i++];
            }
            else
                m1 = nums2[j++];
        }
        else if (i < n)
        {
            m1 = nums1[i++];
        }
        else if (j < m)
        {
            m1 = nums2[j++];
        }
    }

    if ((m + n) % 2 == 1)
        return m1;
    return (double)(m1 + m2) / 2;
}
