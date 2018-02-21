#include <iostream>
#include <string>
const int inf=0x3f3f3f3f;
const int MAXN=200+10;  
using namespace std;

int map[MAXN][MAXN];	//e������¼����
int dis[MAXN];		//dis������¼��ʼ�㵽�����λ��
bool vis[MAXN];		//����Ƿ񱻷���
int n,m;		//n��ʾ���������m��ʾ�ߵ�����

void dijkstra(int s){
	memset(vis, 0, sizeof(vis));//��ʼ���ж�����
	int cur=s;
	dis[cur]=0;
	vis[cur]=1; //�������Ϊ�ѷ���

	//Dijkstra�㷨�������
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!vis[j] && dis[j] > dis[cur] + map[cur][j]){  //����cur��j�ľ���
				dis[j]=dis[cur] + map[cur][j];
			}
		}
		int mini=inf;
		for(int j=0; j<n; j++){
			if(!vis[j] && dis[j]<mini){		//���µ�ǰδ���ʵ���С��dis[cur]
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
		for(int i=1; i<=m; i++){	//�����
			scanf("%d%d%d",&from,&to,&val);
			map[from][to] = map[to][from] = val;
		}

		int s,t;
		scanf("%d%d",&s,&t); //���������յ�
		dijkstra(s);

		if(dis[t]==inf)
			printf("-1\n");
		else
			printf("%d\n",dis[t]);
	}
	system("pause");
	return 0;
}