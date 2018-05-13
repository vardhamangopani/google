/*
Sum of bit differences among all pairs
Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array 
elements. Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y. 
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).
*/

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
