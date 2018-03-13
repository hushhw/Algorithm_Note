/*
人见人爱A^B
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 49614    Accepted Submission(s): 33130


Problem Description
求A^B的最后三位数表示的整数。
说明：A^B的含义是“A的B次方”


Input
输入数据包含多个测试实例，每个实例占一行，由两个正整数A和B组成（1<=A,B<=10000），如果A=0, B=0，则表示输入数据的结束，不做处理。


Output
对于每个测试实例，请输出A^B的最后三位表示的整数，每个输出占一行。


Sample Input
2 3
12 6
6789 10000
0 0


Sample Output
8
984
1


Author
lcy


Source
ACM程序设计期末考试（2006/06/07）


Recommend
lcy   |   We have carefully selected several similar problems for you:  1021 1008 1108 1061 1425 
*/

//又可以学习一波新东西，快速幂

/* 快速幂模板
typedef long long ll; //注意这里不一定都是long long 有时 int 也行  
ll mod_pow(ll x, ll n, ll mod){  
	ll res = 1;  
	while( n > 0 ){   
		if( n & 1 ) res = res * x % mod;    //n&1其实在这里和 n%2表达的是一个意思  
		x = x * x % mod;  
		n >>= 1;                 //n >>= 1这个和 n/=2表达的是一个意思  
	}  
	return res;  
}  

递归版：
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod){
	if(n==0) return 1;
	ll res = mod_pow(x*x%mod, n/2, mod);
	if(n%2==1) res = res*x%mod;
	return res;
}
*/

#include <iostream>
using namespace std;

int main(){
	int m,n,s,i;
	while(scanf("%d%d",&m,&n)!=EOF && (m+n)){
		s=1;
		while(n>0){
			if(n%2==1)
				s = s*m%1000;
			m = m*m%1000;
			n /= 2;
		}
		printf("%d\n",s);
	}
	return 0;
}

/*做完高精度看到这个，，，心态崩了
#include <iostream>
using namespace std;

int main(){
	int m,n,s,i;
	while(scanf("%d%d",&m,&n)!=EOF && (m+n)){
		s=m;
		for(i=1; i<n; i++)
			s = (s*m)%1000;
		printf("%d\n",s);
	}
	return 0;
}
*/
/* 高精度做法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int num[100001];

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF && (a+b)){
		memset(num, 0, sizeof(num));
		int w=0;	//控制进位
		int t=0;	//保留十位
		num[0]=1;
		for(int i=1; i<=b; i++){
			for(int j=0; j<=w; j++){
				num[j] = num[j]*a + t;
				t = num[j]/10;
				num[j] = num[j]%10;
				if(j==w && t!=0)
					w++;
				if(w>=3){
					w--;
					t=0;
					break;
				}
			}
		}

		int ok=0;
		for(int i=2; i>=0; i--){
			if(num[i]==0 && !ok)
				continue;
			if(num[i]!=0)
				ok=1;
			cout<<num[i];
		}
		cout<<endl;
	}
	return 0;
}
*/