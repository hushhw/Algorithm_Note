### 线段树基本概念

线段树/区间树是一种非常常用的对区间数据进行操作的数据结构。 

线段树是一棵二叉树（但不一定是完全二叉树！），它的每个节点均代表一个区间，且父节点代表的区间为左右子节点代表的区间之和。特别的，根节点代表的区间为所有节点代表区间之和，各个叶节点代表区间为单个点（即长度为1的区间）。

### 线段树结构

树中的每一个结点表示了一个区间[a,b]。 a,b通常是整数。每一个叶子节点表示了一个单位区间(长度为1)。对于每一个非叶结点所表示的结点[a,b]，其左儿子表示的区间为[a,(a+b)/2]，右儿子表示的区间为[(a+b)/2+1,b](除法去尾取整）。 

如下图为区间[1, 9]的线段树： 
![线段树](http://7xkwr3.com1.z0.glb.clouddn.com/interval_tree1.PNG)



### 线段树性质

1. 线段树为二分构造，若根节点对应区间为[a,b]，则其深度为 log2(b−a+1)(向上取整）。这样在进行更新查询操作的时候，操作的复杂度就可以为log(n)量级
2. 叶子节点的数目和根节点表示的区间长度相同
3. 若叶子节点的数目为N，则线段树的总节点数目为2*N-1。因为线段树的节点要么是0度，要么为2度，根据二叉树的性质可知。
4. 若叶子节点为N，要想用连续的数组表示一棵线段树，则数组的大小应该为**4N**。 
      因为，根据性质3，线段树总节点数目为2*N-1，又由于线段树不是完全二叉树，因此其最低的叶子一层并不是紧靠最左边，这样在其倒数第二层上的索引号接近2N的位置，按照2*index+1和2*index+2的方式来访问其左右子节点，这就导致整个数组的大小要约为 4*N.
5. 线段树上，任何一个区间被分解后得到的“终止”节点的数目都是log(n)量级。 
   因为每一层最多有两个“终止”节点，共log(n)层，这样在线段树上进行更新叶子节点和进行区间分解的时间复杂度都是O(logn)。



### 基本操作

以[ALGO-8 操作格子](http://lx.lanqiao.cn/problem.page?gpid=T18) 为例，线段树的一些基本操作：

- 建树
- 区间求和
- 区间取最值
- 区间单点修改

```c++
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
```



> 本文整理参考自：
>
> https://www.cnblogs.com/gtarcoder/p/4786734.html