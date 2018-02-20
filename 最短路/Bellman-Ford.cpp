#include <iostream>
#include <vector>

#define INF 9999999
using namespace std;



vector<int> bellmanFord(int src,vector<pair<int,int>> *adj, int n)
{
	vector<int> upper(n,INF);
	upper[src]=0;
	bool updated;

	//松弛操作n次
	for(int iter=0; iter<n; ++iter)
	{
		updated=false;
		for(int here=0; here<n; ++here)
		{
			for(int i=0; i<adj[here].size(); i++)
			{
				int there=adj[here][i].first;
				int cost=adj[here][i].second;
				if(upper[there]>upper[here]+cost)
				{
					upper[there]=upper[here]+cost;
					updated=true;
				}
			}
		}
		//已经找到最短路径，退出
		if(!updated) break;
	}

	//第n次还发生了最短路径的改变，则存在负权回路
	if(updated) upper.clear();
	return upper;
}
//有向图
int main()
{
	//n:顶点个数，m:边的条数
	int n=0,m=0;
	cin>>n>>m;
	//动态定义数组存储每条边，n代表结点个数，在这里即是边的起始点
	vector<pair<int,int>> *adj=new vector<pair<int,int>>[n];
	for(int i=0; i<m; i++)
	{
		int a=0,b=0,c=0;
		//a为边的起始点，b为边的终点，c为边上的权值
		cin>>a>>b>>c;
		//存储的是以a为起点的边
		adj[a].push_back(make_pair(b,c));
	}
	vector<int> result;
	//返回的是各结点处的最短路径距离
	result=bellmanFord(0,adj,n);
	for(int i=0; i<n; i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
}