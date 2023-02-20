#include <iostream>
#define Max 50
int G[Max][Max],n, //ma tran ke
	C[Max];			//mang danh dau dinh
int Init(char *path){
	FILE *f;
	if(!(f = fopen(path,"r")))return 0;
	fscanf(f,"%d",&n);
	int i,j,x;
	while(fscanf(f,"%d%d%d",&i,&j,&x)!= EOF){
		G[i][j] += x;G[j][i] = G[i][j];
	}
	fclose(f);
	return 1;
}
void View_Graph(int G[Max][Max], int n){
	int i, j;
	printf("So dinh: %d\n", n);
	printf("Ma tran ke:\n\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++)
			printf("%d\t", G[i][j]);
		printf("\n \n");
	}
}
int DFS(int u){
	int S[Max], top=1;
	S[top] = u;
	while(top > 0){
		int v = S[top];
		top = top - 1;
		if(C[v] == 1)continue;
		printf("%d\t",v);
		C[v] = 1;
		for(int x = n; x >= 1; x--)
			if(G[x][v] != 0 && C[x] == 0){
				top = top + 1;
				S[top] = x;
			}
	}
	return 1;
}
int main(int argc, char** argv) {
	if(Init((char*)"Graph.INP")){
		View_Graph(G,n);
		DFS(1);
	}
	return 0;
}
