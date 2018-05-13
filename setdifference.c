#include <stdio.h> 
int sumBitDifferences(int arr[], int n)
{
    int ans = 0;  // Initialize result
 
    // traverse over all bits
    for (int i = 0; i < 32; i++)
    {
        // count number of elements with i'th bit set
        int count = 0;
        for (int j = 0; j < n; j++)
            if ( (arr[j] & (1 << i)) )
                count++;
 
        // Add "count * (n - count) * 2" to the answer
        ans += (count * (n - count) * 2);
    }
 
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n%d\n", n,sumBitDifferences(arr, n));
    return 0;
}
