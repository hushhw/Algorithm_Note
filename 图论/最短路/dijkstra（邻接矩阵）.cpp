#include <iostream>
#include <string>
const int inf=0x3f3f3f3f;
const int MAXN=200+10;  
using namespace std;

int map[MAXN][MAXN];	//e用来记录数组
int dis[MAXN];		//dis用来记录初始点到个点的位置
bool vis[MAXN];		//标记是否被访问
int n,m;		//n表示顶点个数，m表示边的条数

void dijkstra(int s){
	memset(vis, 0, sizeof(vis));//初始化判断数组
	int cur=s;
	dis[cur]=0;
	vis[cur]=1; //把起点标记为已访问

	//Dijkstra算法核心语句
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!vis[j] && dis[j] > dis[cur] + map[cur][j]){  //更新cur到j的距离
				dis[j]=dis[cur] + map[cur][j];
			}
		}
		int mini=inf;
		for(int j=0; j<n; j++){
			if(!vis[j] && dis[j]<mini){		//更新当前未访问的最小的dis[cur]
				mini=dis[j];
				cur = j;
			}
		}
		vis[cur]=1;
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		
		for(int i=0; i<n; i++){
			dis[i]=inf;
			for(int j=0; j<n; j++){
				map[i][j]=inf;
			}
		}

		int from,to,val;
		for(int i=1; i<=m; i++){	//读入边
			scanf("%d%d%d",&from,&to,&val);
			map[from][to] = map[to][from] = val;
		}

		int s,t;
		scanf("%d%d",&s,&t); //输入起点和终点
		dijkstra(s);

		if(dis[t]==inf)
			printf("-1\n");
		else
			printf("%d\n",dis[t]);
	}
	system("pause");
	return 0;
}