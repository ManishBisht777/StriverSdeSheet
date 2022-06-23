
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int i = 0, j = 0, count = 0;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            count++;
            if (count == k)
                return arr1[i];
            i++;
        }
        else
        {
            count++;
            if (count == k)
                return arr2[j];
            j++;
        }
    }

    while (i < n)
    {
        count++;
        if (count == k)
            return arr1[i];
        i++;
    }

    while (j < m)
    {
        count++;
        if (count == k)
            return arr2[j];
        j++;
    }

    return -1;
}