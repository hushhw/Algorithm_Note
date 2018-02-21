#include <iostream>
#include <string>
#define inf 0x3f3f3f3f
using namespace std;

int e[100][100];	//e用来记录数组
int dis[100];		//dis用来记录初始点到个点的位置
int book[100];		//标记是否被访问

int main(){
	int n,m;		//n表示顶点个数，m表示边的条数
	scanf("%d%d",&n,&m);

	for(int i=1; i<=n; i++){	//初始化邻接矩阵
		for(int j=1; j<=n; j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}

	int t1,t2,t3;
	for(int i=1; i<=m; i++){	//读入边
		scanf("%d%d%d",&t1,&t2,&t3);
		e[t1][t2] = t3;
	}

	for(int i=1; i<=n; i++)		//初始化dis，为1号点到各点的距离
		dis[i] = e[1][i];

	for(int i=1; i<=n; i++)		//初始化标记数组为0
		book[i] = 0;
	book[1]=1;

	//Dijkstra算法核心语句
	int u,min1;
	for(int i=1; i<=n-1; i++){
		min1 = inf;
		for(int j=1; j<=n; j++){
			if(book[j]==0 && dis[j]<min1){ //找到离1号顶点最近的顶点
				min1 = dis[j];
				u=j;
			}
		}
		book[u]=1;		//找到距离1号点最近的点，标记已访问
		for(int v=1; v<=n; v++){
			if(e[u][v] < inf){
				//如果从起始点到v的距离大于起始点到u的距离加上u到v的距离就更新，专业术语松弛操作
				if(dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}

	//输出1号点到个点距离
	for(int i=1; i<=n; i++)
		printf("%d ", dis[i]);
	system("pause");
	return 0;
}