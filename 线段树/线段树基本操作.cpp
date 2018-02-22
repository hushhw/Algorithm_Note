/*
问题描述
有n个格子，从左到右放成一排，编号为1-n。

共有m次操作，有3种操作类型：

1.修改一个格子的权值，

2.求连续一段格子权值和，

3.求连续一段格子的最大值。

对于每个2、3操作输出你所求出的结果。

输入格式
第一行2个整数n，m。

接下来一行n个整数表示n个格子的初始权值。

接下来m行，每行3个整数p,x,y，p表示操作类型，p=1时表示修改格子x的权值为y，p=2时表示求区间[x,y]内格子权值和，p=3时表示求区间[x,y]内格子最大的权值。

输出格式
有若干行，行数等于p=2或3的操作总数。

每行1个整数，对应了每个p=2或3操作的结果。

样例输入
4 3
1 2 3 4
2 1 3
1 4 3
3 1 4
样例输出
6
3
数据规模与约定
对于20%的数据n <= 100，m <= 200。

对于50%的数据n <= 5000，m <= 5000。

对于100%的数据1 <= n <= 100000，m <= 100000，0 <= 格子权值 <= 10000。
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 100010
using namespace std;

struct node{
	int left,right;//保存左右边界
	int sum,max;//权值和最大值
}a[MAXN*3+1];

int imax(int a,int b){//判断大小的函数   
	return a>b?a:b;
}  

int qMax(int n, int l, int r){	//que=3，求l到r最大权值
	if(l == a[n].left && r == a[n].right)//所求范围与左右范围相等 ，直接输出最大值   
		return a[n].max;  
	int middle = (a[n].left + a[n].right) / 2;  
	if(r <= middle)  
		return qMax(n*2, l, r);//若所求范围在左孩子范围内，从左孩子寻找   
	else if(l > middle)  
		return qMax(n*2+1, l, r);//若所求范围在右孩子范围内，从右孩子寻找  
	else   
		return imax(qMax(n*2, l, middle), qMax(n*2+1, middle+1, r));//若范围在左右孩子之间，分别求最大值，然后求最终最大值
}

int qSum(int n, int l, int r){	//que=2，计算l到r的权值和
	if(l==a[n].left && r==a[n].right)	//若是叶子节点，左右相等，直接返回sum
		return a[n].sum;
	
	int middle = (a[n].left+a[n].right)/2;
	if(r <= middle){ //下面分情况讨论
		return qSum(n*2, l, r);//若在左孩子范围，从左孩子寻找
	} else if(l > middle){
		return qSum(n*2+1, l, r);//若在右孩子范围，从右孩子寻找
	} else	{					//若在之间，分别求解相加
		return (qSum(n*2, l, middle) + qSum(n*2+1, middle+1, r));
	}
}



void change(int n, int l, int r, int num){ 
	//que=1,在区间[l,r]中将r的权值改为num，这题l==r
	if(l==a[n].left && r==a[n].right){		//下标与左右范围相等，存本数
		a[n].sum = num;
		a[n].max = num;
		return ;
	}

	int middle = (a[n].left+a[n].right)/2;
	if(r<=middle)
		change(n*2, l, r, num);	//更新左孩子
	else if(r>middle)
		change(n*2+1, l, r, num);	//更新右孩子
	else{
		change(n*2, l, middle, num);
		change(n*2+1, middle+1, r, num);
	}
	a[n].sum = a[n*2].sum + a[n*2+1].sum;	//更新总和
	a[n].max = imax(a[n*2].max, a[n*2+1].max);	//更新最大值
}

void build(int n, int l, int r){
	if(l==r){		//如果左右间距相等,说明是叶子节点
		a[n].left = l;
		a[n].right = r;
		scanf("%d",&a[n].sum);
		a[n].max = a[n].sum;
		return ;
	}

	int middle = (l+r)/2;
	a[n].left = l;		//左边距
	a[n].right = r;		//右边距
	build(n*2, l, middle);	//构建l至mid的左孩子
	build(n*2+1, middle+1, r);	//构建mid+1到r的右孩子

	a[n].sum = a[n*2].sum + a[n*2+1].sum;
	a[n].max = imax(a[n*2].max, a[n*2+1].max);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);	//构建一个范围为1到n的线段树

	int que,b,c;
	while(m--){
		scanf("%d%d%d",&que, &b, &c);
		switch(que){
			case 1:
				change(1,b,b,c); break;//改变节点b的权值为c  
			case 2:
				printf("%d\n", qSum(1,b,c)); break;//计算b至c范围内的权值和   
			case 3:
				printf("%d\n", qMax(1,b,c)); break;//计算b至c范围内的最大权值   
			default: break;
		}
	}
	system("pause");
	return 0;
}