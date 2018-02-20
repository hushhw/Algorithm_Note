熟悉的最短路算法就几种：**bellman-ford，dijkstra，spfa，floyd**，下面针对这几个算法具体解析一下。首先说明一点，就是关于负环的问题。
bellman-ford可以用于边权为负的图中，图里有负环也可以，如果有负环，算法会检测出负环。
dijkstra只能用于边权都为正的图中。
spfa是个bellman-ford的优化算法，本质是bellman-ford，所以适用性和bellman-ford一样。
floyd可以用于有负权的图中，即使有负环，算法也可以检测出来。

任何题目中都要注意的有四点事项：图是有向图还是无向图、是否有负权边，是否有重边，顶点到自身的可达性。这几点非常重要，可以在我下面的讲解中体会。



## dijkstra(单源最短路径)

这个算法只能计算单元最短路，而且不能计算负权值，这个算法是贪心的思想， dis数组用来储存起始点到其他点的最短路，但开始时却是存的起始点到其他点的初始路程。通过n-1遍的遍历找最短。 
比如1到3的最短路就是比较dis[3]与dis[2]+e[2]\[3]，如果大于的话就更新dis[3]位dis[2]+e[2]\[3]，这个专业术语叫松弛，这种算法的核心思想就是通过边来松弛一号顶点到其他定点的路程，这也就能解释为什么要遍历n-1遍了。 
book数组用来标记，被标记的是已经找过的最短路，没被标记的没有被找过的最短路，当全部找过以后算法结束，也就是说dis数组中的数是起始点到其他所有点的最短路 ，以下为完整代码：

```c++
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
```



## bellman-ford

Dijkstra 算法是处理单源最短路径的有效算法，但它对存在负权回路的图就会失效。这时候，就需要使用其他的算法来应对这个问题，Bellman-Ford算法就是其中一个。

Bellman-Ford 算法不仅可以求出最短路径，也可以检测负权回路的问题。该算法由美国数学家理查德 • 贝尔曼（Richard Bellman, 动态规划的提出者）和小莱斯特 • 福特（Lester Ford）发明。



**算法特点（权值可正可负，用来判断负环）**

1.Bellman_Frod可以计算边权为负值的最短路问题，适用于有向图和无向图.用来求解源点到达任意点的最短路。

2.在边权可正可负的图中，环有零环，正环，负环3种。如果包含零环和正环的话，去掉以后路径不会变长，如果包含负环则最短路是不存在的。那么既然不包含负环，所以最短路除了源点以外最多只经过n-1条边，这样就可以通过n-1次的松弛得到源点到每个点的最短路径。

3.时间复杂度o(n*m);

4.如果存在环的话就是经过n-1次松弛操作后还能更新dis数组。









> 本文整理自：
>
> http://blog.csdn.net/mmy1996/article/details/52225893