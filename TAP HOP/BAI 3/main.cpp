#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int A[10],n,B[10],m,C[10],k;
//Doc tap hop tu file
int Init(int M[], int &k,char *path){
	 FILE *fptr;
	 if(! (fptr = fopen(path,"r")))return 0;
	 k = 0;
	 while(fscanf(fptr,"%d",&M[k]) != EOF) k++;
	fclose(fptr);
	return 1;
}
//Xoa cac phan tu trung
void Delete(int M[], int &n){
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(M[i] == M[j]){
				for(int k = j; k < n -1; k++) M[k] = M[k+1];
				n = n - 1; j = j - 1;
			}
}

void Print(int M[], int n){
	for(int i = 0; i < n; i++) printf("%d\t",M[i]);
	printf("\n");
}

void union_set(int A[], int n, int B[], int m, int C[], int &k){
	for(int i = 0; i < n ; i++)C[i] = A[i];
	 k = n;
	for(int i = 0; i < m; i++){
		int ok = 1;
	   for(int j = 0; j < k && ok ; j++)
	   		if(C[j] == B[i])ok = 0;
	   	if(!ok) continue;
	   	C[k] = B[i]; k = k + 1;
	}
}

int main(int argc, char** argv) {
	  if(Init(A,n,(char*)"Set_A.INP") && Init(B,m,(char*)"Set_B.INP")){
			printf("A: \t");
			Print(A,n);
			printf("\nB:\t");
			Print(B,m);
			Delete(A,n); 
			Delete(B,m);
			union_set(A,n,B,m,C,k); printf("\nC:\t");Print(C,k);
	}
	return 0;
}
