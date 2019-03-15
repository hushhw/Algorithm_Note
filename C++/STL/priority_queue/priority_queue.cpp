#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <functional> //因为用了greater<int>() 
#include <queue>
using namespace std;

/*	默认的优先队列（非结构体结构）输出结果为从大到小的排序
	
priority_queue <int> q;

int main(){
	int a[]={10, 8, 12, 14, 6};
	for(int i=0; i<5; i++) q.push(a[i]);
	while(!q.empty()){
		printf("%d ",q.top()); //14 12 10 8 6
		q.pop();
	}
	system("pause");
	return 0;
}

*/

/*  默认的优先队列（结构体）

struct node{
	int x, y;
	node(int xx, int yy){
		x=xx;
		y=yy;
	}
	bool operator < (const node & a) const{
		return x < a.x;
	}
};

int main(){
	priority_queue <node> q;
	q.push(node(10, 100));
	q.push(node(12,60));
	q.push(node(14,40));
	q.push(node(6,80));
	q.push(node(8,20));
	while(!q.empty()){
		printf("(%d,%d) ",q.top().x,q.top().y); 
		//(14,40) (12,60) (10,100) (8,20) (6,80)
		q.pop();
	}
	system("pause");
	return 0;
}

*/


int main()
{
	priority_queue <int,vector<int>,less<int> > p;
	priority_queue<int, vector<int>, greater<int> > q;
	int a[5]={10,12,14,6,8};

	for(int i=0;i<5;i++)
		p.push(a[i]),q.push(a[i]);

	printf("less<int>:");
	while(!p.empty())
		printf("%d ",p.top()),p.pop();  

	printf("\ngreater<int>:");
	while(!q.empty())
		printf("%d ",q.top()),q.pop();

	system("pause");
	return 0;
}