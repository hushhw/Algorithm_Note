#include <iostream>
#include <string>
#include <queue>
const int inf=0x3f3f3f3f;
const int MAXN=200+10;  
using namespace std;

int dis[MAXN][MAXN];
int n,m;			//n表示顶点个数，m表示边的条数



void floyd(){
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
}

int main(){
	while(~scanf("%d%d",&n,&m)){

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dis[i][j]=inf;

		for(int i=0; i<m; i++){
			int from, to, val;
			scanf("%d%d%d",&from,&to,&val);
			if(dis[from][to] > val)  
				dis[to][from]=dis[from][to]=val; 
		}
		int s,t;
		scanf("%d%d",&s,&t); //输入起点和终点
		if(s==t){
			printf("0\n");
			continue;
		}
		floyd();

		if(dis[s][t]==inf)
			printf("-1\n");
		else
			printf("%d\n",dis[s][t]);
	}
	system("pause");
	return 0;
}