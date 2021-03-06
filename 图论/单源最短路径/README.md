最短路径

- dijkstra
- SPFA
- floyd



## dijkstra(单源最短路径)

Dijkstra单源最短路算法，即计算从起点出发到每个点的最短路。Dijkstra常常作为其他算法的预处理。

- 使用邻接矩阵的时间复杂度为O(n^2)
- 用邻接表+优先队列（堆）的时间复杂度为O((m+n)logn)近似为O(mlogn)

这个算法只能计算单元最短路，而且不能计算负权值，这个算法是贪心的思想， dis数组用来储存起始点到其他点的最短路，但开始时却是存的起始点到其他点的初始路程。通过n-1遍的遍历找最短。 
比如1到3的最短路就是比较dis[3]与dis[2]+e[2]\[3]，如果大于的话就更新dis[3]位dis[2]+e[2]\[3]，这个专业术语叫松弛，这种算法的核心思想就是通过边来松弛一号顶点到其他定点的路程，这也就能解释为什么要遍历n-1遍了。 
book数组用来标记，被标记的是已经找过的最短路，没被标记的没有被找过的最短路，当全部找过以后算法结束，也就是说dis数组中的数是起始点到其他所有点的最短路 。

以下为以 [HDU 1874 畅通工程续](http://acm.hdu.edu.cn/showproblem.php?pid=1874) 完整代码：

1. dijkstra+邻接矩阵

```c++
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
```

2. dijkstra+优先队列

```c++
#include <iostream>
#include <string>
#include <queue>
const int inf=0x3f3f3f3f;
const int MAXN=200+10;  
using namespace std;

int head[MAXN],len;		//记录数组
int dis[MAXN];		//dis用来记录初始点到个点的位置
bool vis[MAXN];		//标记是否被访问
int n,m;			//n表示顶点个数，m表示边的条数

struct edge{
	int to, val, next;
}e[MAXN];

void add(int from, int to, int val){
	e[len].to=to;
	e[len].val=val;
	e[len].next=head[from];
	head[from]=len++;
}

struct point{
	int val, id;
	point(int id,int val):id(id),val(val){}
	bool operator <(const point &x)const{
		return val>x.val;
	}
};

void dijkstra(int s){
	memset(vis, 0, sizeof(vis));	//初始化判断数组
	for(int i=0; i<n; i++)
		dis[i] = inf;
	priority_queue<point> q;
	q.push(point(s,0));
	dis[s]=0;
	while(!q.empty()){
		int cur=q.top().id;
		q.pop();
		if(vis[cur]) continue;
		vis[cur]=true;
		for(int i=head[cur]; i!=-1; i=e[i].next){
			int id=e[i].to;
			if(!vis[id] && dis[cur]+e[i].val < dis[id]){
				dis[id]=dis[cur]+e[i].val;
				q.push(point(id, dis[id]));
			}
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		len=0;
		memset(head, -1, sizeof(head));
		for(int i=0; i<m; i++){
			int from, to, val;
			scanf("%d%d%d",&from,&to,&val);
			add(from, to, val);
			add(to, from, val);
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
```



## SPFA（bellman-ford）

SPFA是bellman-ford算法的队列实现版本（貌似也改进了点）

SPFA的实现如下：

用数组dis记录更新后的状态，cnt记录更新的次数，队列q记录更新过的顶点，算法依次从q中取出顶点v,按照dis(k)[u]=min{dis(k-1)[v]+e(v,u)}的递归式更新。在计算过程中，一旦发现顶点K有cnt[k]>n，说明有一个从顶点K出发的负权圈，此时没有最短路，应终止算法。否则，队列为空的时候，算法得到G的各顶点的最短路径长度。

 下面举一个实例来说明SFFA算法是怎样进行的：
![img](http://www.layz.net/LAOJ/suanfa/pic/s9-4-1.jpg)
![img](http://www.layz.net/LAOJ/suanfa/pic/s9-4-2.jpg)

1.邻接矩阵的SPFA [HDU 1874 畅通工程续](http://acm.hdu.edu.cn/showproblem.php?pid=1874)



```c++
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

void SPFA(int s){
	for(int i=0; i<n; i++)
		dis[i]=inf;
	memset(vis, 0, sizeof(vis));
	vis[s]=1;
	dis[s]=0;

	queue<int> q;
	q.push(s);

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
```

2. 邻接表的SPFA（推荐）[HDU 1874 畅通工程续](http://acm.hdu.edu.cn/showproblem.php?pid=1874)

```
#include <iostream>
#include <string>
#include <queue>
const int inf=0x3f3f3f3f;
const int MAXN=200+10;  
using namespace std;

int head[MAXN],len;	
int dis[MAXN];		//dis用来记录初始点到个点的位置
bool vis[MAXN];		//标记是否被访问
int n,m;			//n表示顶点个数，m表示边的条数

struct edge{
	int to, val, next;
}e[MAXN];

void add(int from, int to, int val){
	e[len].to=to;
	e[len].val=val;
	e[len].next=head[from];
	head[from]=len++;
}


void SPFA(int s){
	memset(vis, 0, sizeof(vis));	//初始化判断数组
	for(int i=0; i<n; i++)
		dis[i] = inf;

	queue<int> q;
	q.push(s);
	vis[s]=true;
	dis[s]=0;

	while(!q.empty()){
		int cur=q.front();
		q.pop();
		vis[cur]=false;
		for(int i=head[cur]; i!=-1; i=e[i].next){
			int id=e[i].to;
			if(dis[id] > dis[cur]+e[i].val){
				dis[id] = dis[cur]+e[i].val;
				if(!vis[id]){
					vis[id]=true;
					q.push(id);
				}
			}
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		len=0;
		memset(head, -1, sizeof(head));

		for(int i=0; i<m; i++){
			int from, to, val;
			scanf("%d%d%d",&from,&to,&val);
			add(from, to, val);
			add(to, from, val);
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
```



## floyd

**Floyd-Warshall算法**（Floyd-Warshall algorithm）是解决任意两点间的最短路径的一种算法，可以正确处理有向图或负权的最短路径问题，同时也被用于计算有向图的传递闭包。Floyd-Warshall算法的时间复杂度为$O(N^3)$，空间复杂度为$O(N^2)$。

这是一个dp（动态规划的过程）
dis[i]\[j]=min(dis[i]\[j],dis[i]\[k]+dis[k]\[j]);
即从顶点i到j且经过顶点k的最短路径长度。

```c++
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
```



> 本文整理自：
>
> http://blog.csdn.net/acm_1361677193/article/details/48211319
>
> http://blog.csdn.net/xunalove/article/details/70045815