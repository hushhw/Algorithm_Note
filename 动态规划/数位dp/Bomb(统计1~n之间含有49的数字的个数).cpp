/*
Bomb
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 131072/65536 K (Java/Others)
Total Submission(s): 21198    Accepted Submission(s): 7939

Problem Description
The counter-terrorists found a time bomb in the dust. But this time the terrorists improve on the time bomb. The number sequence of the time bomb counts from 1 to N. If the current number sequence includes the sub-sequence "49", the power of the blast would add one point.
Now the counter-terrorist knows the number N. They want to know the final points of the power. Can you help them?

Input
The first line of input consists of an integer T (1 <= T <= 10000), indicating the number of test cases. For each test case, there will be an integer N (1 <= N <= 2^63-1) as the description.
The input terminates by end of file marker.

Output
For each test case, output an integer indicating the final points of the power.

Sample Input
3
1
50
500

Sample Output
0
1
15

Hint
From 1 to 500, the numbers that include the sub-sequence "49" are "49","149","249","349","449","490","491","492","493","494","495","496","497","498","499",
so the answer is 15.

Author
fatboy_cw@WHU
Source
2010 ACM-ICPC Multi-University Training Contest（12）——Host by WHU
Recommend
zhouzeyong

题意：
统计1~n之间含有49的数字的个数(1 <= n <= 10000)
*/

#include <iostream>
#include <string>
using namespace std;

const int N=20;
int dp[N][10][2]; //dp[i][j][z],i表示当前位数，j表示上一位，istrue表示是否符合49
int dig[N];

int dfs(int pos, int pre, int istrue, int limit){
	cout<<limit<<endl;
	if(pos < 0) return istrue;
	if(!limit && dp[pos][pre][istrue]!=-1)
		return dp[pos][pre][istrue];
	int last = limit? dig[pos]:9;
	int ret = 0;
	for(int i=0; i<=last; i++){
		ret += dfs(pos-1, i, istrue || (pre==4 && i==9), limit && (i==last));
	}
	if(!limit){
		dp[pos][pre][istrue] = ret;
	}
	return ret;
}

int solve(int n){
	int len=0;
	while(n){
		dig[len++] = n%10;
		n /= 10;
	}
	return dfs(len-1, 0, 0, 1); //从高位开始递归
}

int main(){
	memset(dp, -1, sizeof(dp));
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cout<<solve(n)<<endl;
	}
	return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

int dp[10][10];


void init(){
	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	for(int i=1; i<=5; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				if(!(j==4 && k==9))
					dp[i][j] += dp[i-1][k];
			}
		}
	}
}

int solve(int n){
	init();
	int num[10];
	int ans=0;
	int tot=1;
	while(n){
		num[tot++] = n%10;
		n /= 10;
	}
	for(int i=tot; i>=1; i--){
		for(int j=0; j<num[i]; j++){
			if(!(j==9 && num[i+1]==4))
				ans += dp[i][j];
		}
		if(num[i]==9 && num[i+1]==4)
			break;
	}
	return ans;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		cout<<n - solve(n)<<endl;
	}
	return 0;
}
*/