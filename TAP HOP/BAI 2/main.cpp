#include <iostream>
#include <stdio.h>
int M[15],n, card;

int Init(int M[], int &n, char *path){
	FILE *fptr;
	if(!(fptr = fopen(path,"r")))return 0;
	int x=0;
	while(fscanf(fptr,"%d",&x)!= EOF){
		if(M[x] == 0)card++;
		M[x] = 1;
		n = (x > n) ? x : n;
	}
	fclose(fptr);
	return 1;
}

int Printf(int M[], int n){
	for(int i = 1; i <= n; i++)
		if(M[i] == 1)printf("%d ",i);
	printf("\nXau bit:\n");
	for(int i = 1; i <= n; i++)
		printf("%d ",M[i]);
	printf("\n");
}

int main(int argc, char** argv){
	if(Init (M,n, (char*)"Set.INP")){
		Printf(M,n);
		printf("Luc luong: %d\n", card);
	}
	return 0;
}

