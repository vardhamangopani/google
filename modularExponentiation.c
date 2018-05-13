/*
Given three numbers x, y and p, compute (x^y) % p.
*/

#include<stdio.h>
int getModularExponentiation(int x, int y, int p){
	if(y==0)
		return 1;
	else
		return ((x%p)*(getModularExponentiation(x,y-1,p)%p))%p;
}

int main(){
	printf("Answer = %d\n",getModularExponentiation(2,5,13));
	return 0;
}
