#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int A[20],n,B[20],m,C[20],k;
int Init(int M[],int &k,char *path){
		FILE *fptr;
		if(!(fptr = fopen(path,"r")))return 0;
		k = 0;
		while(fscanf(fptr,"%d",&M[k])!=EOF)k++;
	fclose(fptr);
	return 1;
}
//Xoa cac phan tu trung
void Delete(int M[],int &n){
		for(int i = 0;i<n - 1;i++)
		  for(int j = i+1;j<n;j++)
		    if(M[i] == M[j]){
		      for(int k = j; k< n-1;k++)M[k] = M[k+1];
		      n = n - 1; j = j - 1;
			}
}
void Print(int M[], int n){
 for(int i = 0;i<n;i++)printf("%3d",M[i]);
 printf("\n");
}
void intersection(int A[], int n, int B[], int m, int C[], int &k){
	for(int i = 0; i<n ; i++)
		for(int j = 0; j< m;j++)
						if(B[j] == A[i]){
							C[k] = A[i]; k++;
						}
}
int main(int argc, char** argv) {
		if(Init(A,n,(char*)"SetA.INP")&& Init(B,m,(char*)"SetB.INP")){
		printf("A:\t");Print(A,n); printf("\nB:\t");Print(B,m);
		Delete(A,n); Delete(B,m);
		intersection(A,n,B,m,C,k); printf("\nC:\t");Print(C,k);
		}
	return 0;
}
