#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int A[10],n,B[10],m,C[10],k,card;
int Init(int M[], int &n, char *path){
	FILE *fptr;
	if(!(fptr = fopen(path,"r")))return 0;
	int x = 0;
	while(fscanf(fptr,"%d",&x)!= EOF){
		if(M[x] == 0)card++;
		M[x] = 1;
		n = (x > n) ? x : n;
	}
	fclose(fptr);
	return 1;
}
int Print(int M[], int n){
	for(int i = 1; i<= n; i++)
		if(M[i] == 1)printf("%d ",i);
	printf("\nXau bit:\n");
	for(int i = 1; i <= n; i++)
		printf("%d ",M[i]);
	printf("\n");
}

int Intersec(int A[], int n, int B[], int m, int C[], int &k){
	int resul = 0;
	k = (n > m) ? n : m;
	for(int i = 1; i <= k; i++){
		C[i] = (A[i] == 1 && B[i] == 1);
		resul = resul + 1;
	}
	return resul;
}

int main(int argc, char** argv) {
	if(Init (A,n, (char*)"Set_A.INP") && Init(B,m,(char*)"Set_B.INP")){
		printf("A:\t");Print(A,n);
		printf("\nB:\t");Print(B,m);
		Intersec(A,n,B,m,C,k);
		printf("\nC:\t");Print(C,k);
	}
	return 0;
}
