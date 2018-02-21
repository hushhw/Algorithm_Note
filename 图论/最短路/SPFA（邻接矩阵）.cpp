#include <iostream>
#include <string>
#include <queue>
const int inf=0x3f3f3f3f;
const int MAXN=200+10;  
using namespace std;

int map[MAXN][MAXN];		//记录数组
int dis[MAXN];		//dis用来记录初始点到个点的位置
bool vis[MAXN];		//标记是否被访问
int n,m;			//n表示顶点个数，m表示边的条数

void SPFA(int s){	//求单源点s到其他个顶点的最短距离
	for(int i=0; i<n; i++)
		dis[i]=inf;
	memset(vis, 0, sizeof(vis));
	vis[s]=1;
	dis[s]=0;

	queue<int> q;	
	q.push(s);		//源点s入队

	while(!q.empty()){
		int cur=q.front();
		q.pop();
		vis[cur]=false;
		for(int i=0; i<n; i++){
			if(dis[i] > dis[cur] + map[cur][i]){
				dis[i] = dis[cur] + map[cur][i];
				if(!vis[i]){
					q.push(i);
					vis[i]=true;
				}
			}
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				map[i][j]=inf;
			}
		}

		int from,to,val;
		for(int i=1; i<=m; i++){	//读入边
			scanf("%d%d%d",&from,&to,&val);
			if(map[from][to]>val)
				map[from][to] = map[to][from] = val;
		}

		int s,t;
		scanf("%d%d",&s,&t); //输入起点和终点
		SPFA(s);

		if(dis[t]==inf)
			printf("-1\n");
		else
			printf("%d\n",dis[t]);
	}
	system("pause");
	return 0;
}