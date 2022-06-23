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

// binary search

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int n = nums1.size();
    int m = nums2.size();

    if (m < n)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = n;

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n ? INT_MAX : nums1[cut1];
        int right2 = cut2 == m ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((m + n) % 2 == 0)
                return (double)(max(left1, left2) + min(right1, right2)) / 2;
            else
                return max(left1, left2);
        }

        else if (left1 > right2)
            high = cut1 - 1;

        else
            low = cut1 + 1;
    }

    return 0.0;
}