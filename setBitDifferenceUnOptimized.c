/*
Sum of bit differences among all pairs
Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array 
elements. Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y. 
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).
*/

#include<stdio.h>
int setBitDifference(int arr[], int n){
	int ans=0;
	int i, j, k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=0;k<32;k++){
				if( (arr[i] & (1<<k)) ^ (arr[j] & (1<<k)) )
					ans++; 
			}
		}
	}
	return ans*2;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n%d\n",n,setBitDifference(arr, n));
    return 0;
}
