#include <iostream>
#include <vector>

#define INF 9999999
using namespace std;



vector<int> bellmanFord(int src,vector<pair<int,int>> *adj, int n)
{
	vector<int> upper(n,INF);
	upper[src]=0;
	bool updated;

	//�ɳڲ���n��
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
		//�Ѿ��ҵ����·�����˳�
		if(!updated) break;
	}

	//��n�λ����������·���ĸı䣬����ڸ�Ȩ��·
	if(updated) upper.clear();
	return upper;
}
//����ͼ
int main()
{
	//n:���������m:�ߵ�����
	int n=0,m=0;
	cin>>n>>m;
	//��̬��������洢ÿ���ߣ�n����������������Ｔ�Ǳߵ���ʼ��
	vector<pair<int,int>> *adj=new vector<pair<int,int>>[n];
	for(int i=0; i<m; i++)
	{
		int a=0,b=0,c=0;
		//aΪ�ߵ���ʼ�㣬bΪ�ߵ��յ㣬cΪ���ϵ�Ȩֵ
		cin>>a>>b>>c;
		//�洢������aΪ���ı�
		adj[a].push_back(make_pair(b,c));
	}
	vector<int> result;
	//���ص��Ǹ���㴦�����·������
	result=bellmanFord(0,adj,n);
	for(int i=0; i<n; i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
}