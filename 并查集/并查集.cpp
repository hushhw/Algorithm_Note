/*
畅通工程
Time Limit: 4000/2000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 61184    Accepted Submission(s): 32757


Problem Description
某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？ 


Input
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
注意:两个城市之间可以有多条道路相通,也就是说
3 3
1 2
1 2
2 1
这种输入也是合法的
当N为0时，输入结束，该用例不被处理。 


Output
对每个测试用例，在1行里输出最少还需要建设的道路数目。 


Sample Input
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0


Sample Output
1
0
2
998

*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int pre[1000];
int total;

int find(int x){
	int r=x;
	while(pre[r]!=r)	//如果r的上级不是自己
		r=pre[r];		//那么r等于它的前导点，继续寻找，直到找到根节点
	
	//下面这段起到路径压缩的作用
	int i=x; int j;
	while(i!=r)			//如果当前查找的城镇不是根结点（pre指向自己）
	{
		j=pre[i];		//j为该城镇的前导点
		pre[i]=r;		//更新该城镇的前导点直接指向根节点
		i=j;			//让i指向其前导点，在下一次循环里面就会更新其前导点指向根节点
	}
	return r;
}

void join(int p1,int p2){
	int f1,f2;
	f1 = find(p1);
	f2 = find(p2); //分别查找两个城镇的根节点
	//如果是不连通的，那么把这两个分支连起来
	//分支的总数就减少了1，还需建的路也就减了1
	if(f1!=f2)
	{
		pre[f2 ]=f1;
		total--;
	}
}

int main(){
	int  n,m,p1,p2;
	while((~scanf("%d",&n)) && n){
		total = n-1; //最差的情况下，总共要修n-1条路

		for(int i=1;i<=n;i++) { //初始化pre数组，让他们的前导点都记录为自己，即自己为根节点
			pre[i]=i; 
		}

		cin>>m;
		while(m--){
			cin>>p1>>p2; //输入相连的连个城镇
			join(p1,p2);
		}
		printf("%d\n",total); //最后输出还要修的路条数
	}
	system("pause");
	return 0;
}