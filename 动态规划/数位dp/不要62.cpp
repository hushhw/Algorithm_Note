/*
Problem Description
杭州人称那些傻乎乎粘嗒嗒的人为62（音：laoer）。
杭州交通管理局经常会扩充一些的士车牌照，新近出来一个好消息，以后上牌照，不再含有不吉利的数字了，这样一来，就可以消除个别的士司机和乘客的心理障碍，更安全地服务大众。
不吉利的数字为所有含有4或62的号码。例如：
62315 73418 88914
都属于不吉利号码。但是，61152虽然含有6和2，但不是62连号，所以不属于不吉利数字之列。
你的任务是，对于每次给出的一个牌照区间号，推断出交管局今次又要实际上给多少辆新的士车上牌照了。

Input
输入的都是整数对n、m（0<n≤m<1000000），如果遇到都是0的整数对，则输入结束。

Output
对于每个整数对，输出一个不含有不吉利数字的统计个数，该数值占一行位置。

Sample Input
1 100 0 0

Sample Output
80

Author
qianneng
Source
迎接新学期——超级Easy版热身赛

题意：

区间[l,r]内数字的数位不含62且不含4的数的个数

*/
/*
#include <iostream>
#include <string>
using namespace std;

int dp[10][10];

void init(){
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=1; i<=7; i++){		
		for(int j=0; j<10; j++){	//枚举第i位数上的数字
			for(int k=0; k<10; k++){//枚举第i-1为数上的数字
				if(j!=4 && !(j==6 && k==2))//满足条件
					dp[i][j] += dp[i-1][k];
			}
		}
	}
}

int solve(int n){
	init();
	int digit[10];			//存储每位数字
	int len = 1;			//位数
	while(n){
		digit[len++]=n%10;
		n /= 10;
	}
	int ans=0;				//记录满足条件的结果
	for(int i=len; i>=1; i--){	//从最高为开始遍历
		for(int j=0; j<digit[i]; j++){
			if(j!=4 && !(digit[i+1]==6 && j==2))
				ans += dp[i][j];
		}
		if(digit[i]==4 || (digit[i+1]==6 && digit[i]==2)) ////第i位已经不满足条件，则i位以后都不可能满足条件，结束循环  
			break;
	}
	return ans;
}

int main(){
	int l,r;
	while(cin>>l>>r){
		if(l+r==0)
			break;
		else
			cout<<solve(r+1)-solve(l)<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;

int dp[10][2]; //dp[i][j]表示，当前第i位，前一位是否是6的状态
int a[20];
int l,r,tot;

//pos表示当前位置，pre表示前一个数，sta表示当前状态，也就是之前是否为6
//lim表示当前是否是有限制的，比如967，当我们第一个数选择9时，第二个数就只能选择0-6了
int dfs(int pos, int pre, int sta, int lim){
	int cur=0;
	if(pos==0) return 1; //如果执行到0了，当前构成的数可行
	if(!lim && dp[pos][sta]!=-1) return dp[pos][sta];
	int up = lim? a[pos]:9; //是否有限制判断
	for(int i=0; i<=up; i++){
		if(i==4 || (pre==6 && i==2)) //如果当前数字为4，或者前一个数字为6，当前位2，排除
			continue;
		cur += dfs(pos-1, i, i==6, lim&&i==a[pos]);
	}
	if(!lim) dp[pos][sta]=cur;
	return cur;
}

int solve(int x){
	tot = 0;	//tot用来记录位数
	while(x){
		a[++tot]=x%10;
		x /= 10;
	}
	return dfs(tot,-1,0,1);
}

int main(){
	while(~scanf("%d%d",&l,&r)&&(l+r)){
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(r)-solve(l-1));
	}
	return 0;
}
