#include <iostream>
#include <stdio.h>

int A[5]={1,1,2,4,2},
	S[5]={1,1,1,1,1},
	n = 5;
		
int card(int A[], int S[], int n){
	int s = 0;
	for(int i = 0;i < n; i++)
		if(S[i] == 1){
			for(int j = i + 1;j < n;j++)
				if(A[i] == A[j])
					S[j] = 0;
					S[i]=0;
					s++;
		}
	return s;
}

int main() {
	printf("card(A) = %d", card(A,S,n));
	return 0;
}
