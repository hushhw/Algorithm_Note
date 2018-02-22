#include <iostream>
#include <string>
#define inf 0x3f3f3f3f
using namespace std;

int e[100][100];	//e������¼����
int dis[100];		//dis������¼��ʼ�㵽�����λ��
int book[100];		//����Ƿ񱻷���

int main(){
	int n,m;		//n��ʾ���������m��ʾ�ߵ�����
	scanf("%d%d",&n,&m);

	for(int i=1; i<=n; i++){	//��ʼ���ڽӾ���
		for(int j=1; j<=n; j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}

	int t1,t2,t3;
	for(int i=1; i<=m; i++){	//�����
		scanf("%d%d%d",&t1,&t2,&t3);
		e[t1][t2] = t3;
	}

	for(int i=1; i<=n; i++)		//��ʼ��dis��Ϊ1�ŵ㵽����ľ���
		dis[i] = e[1][i];

	for(int i=1; i<=n; i++)		//��ʼ���������Ϊ0
		book[i] = 0;
	book[1]=1;

	//Dijkstra�㷨�������
	int u,min1;
	for(int i=1; i<=n-1; i++){
		min1 = inf;
		for(int j=1; j<=n; j++){
			if(book[j]==0 && dis[j]<min1){ //�ҵ���1�Ŷ�������Ķ���
				min1 = dis[j];
				u=j;
			}
		}
		book[u]=1;		//�ҵ�����1�ŵ�����ĵ㣬����ѷ���
		for(int v=1; v<=n; v++){
			if(e[u][v] < inf){
				//�������ʼ�㵽v�ľ��������ʼ�㵽u�ľ������u��v�ľ���͸��£�רҵ�����ɳڲ���
				if(dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}

	//���1�ŵ㵽�������
	for(int i=1; i<=n; i++)
		printf("%d ", dis[i]);
	system("pause");
	return 0;
}