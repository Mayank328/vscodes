class Solution
{
public:
    int total_sum(int a[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i += 1)
        {
            sum += a[i];
        }
        return sum;
    }
    int findmax(int a[], int n)
    {
        int ans = INT_MIN;
        for (int i = 0; i < n; i += 1)
        {
            ans = max(ans, a[i]);
        }
        return ans;
    }
    int possible(int a[], int n, int m, int pg)
    {
        long long curr_pg = 0;
        int count = 1;
        for (int i = 0; i < n; i += 1)
        {
            if (curr_pg + a[i] <= pg)
            {
                curr_pg += a[i];
            }
            else
            {
                count += 1;
                curr_pg = a[i];
            }
        }
        return count;
    }
    int findPages(int a[], int n, int m)
    {
        if (m > n)
            return -1;
        int low = findmax(a, n);
        int high = total_sum(a, n);
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int studs = possible(a, n, m, mid);
            if (studs > m)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};