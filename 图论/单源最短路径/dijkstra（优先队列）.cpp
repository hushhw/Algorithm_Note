#include <iostream>
#include <string>
#include <queue>
const int inf=0x3f3f3f3f;
const int MAXN=200+10;  
using namespace std;

int head[MAXN],len;		//��¼����
int dis[MAXN];		//dis������¼��ʼ�㵽�����λ��
bool vis[MAXN];		//����Ƿ񱻷���
int n,m;			//n��ʾ���������m��ʾ�ߵ�����

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
	memset(vis, 0, sizeof(vis));	//��ʼ���ж�����
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