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
