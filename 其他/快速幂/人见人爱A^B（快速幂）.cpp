/*
�˼��˰�A^B
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 49614    Accepted Submission(s): 33130


Problem Description
��A^B�������λ����ʾ��������
˵����A^B�ĺ����ǡ�A��B�η���


Input
�������ݰ����������ʵ����ÿ��ʵ��ռһ�У�������������A��B��ɣ�1<=A,B<=10000�������A=0, B=0�����ʾ�������ݵĽ�������������


Output
����ÿ������ʵ���������A^B�������λ��ʾ��������ÿ�����ռһ�С�


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
ACM���������ĩ���ԣ�2006/06/07��


Recommend
lcy   |   We have carefully selected several similar problems for you:  1021 1008 1108 1061 1425 
*/

//�ֿ���ѧϰһ���¶�����������

/* ������ģ��
typedef long long ll; //ע�����ﲻһ������long long ��ʱ int Ҳ��  
ll mod_pow(ll x, ll n, ll mod){  
	ll res = 1;  
	while( n > 0 ){   
		if( n & 1 ) res = res * x % mod;    //n&1��ʵ������� n%2������һ����˼  
		x = x * x % mod;  
		n >>= 1;                 //n >>= 1����� n/=2������һ����˼  
	}  
	return res;  
}  

�ݹ�棺
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

/*����߾��ȿ��������������̬����
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
/* �߾�������
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
		int w=0;	//���ƽ�λ
		int t=0;	//����ʮλ
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