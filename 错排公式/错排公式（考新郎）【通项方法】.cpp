#include <cstdio>
#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;

long long f[22];  


int c(int n){  
	ll sum=1;
	for(int i=1; i<=n; i++)
		sum*=i;
	return sum;
}

int main(){  
	int N,M;   
	while(scanf("%d%d",&N,&M)!=EOF)  
	{  
		ll a=c(N), sum=0, b=c(N-M);
		for(int i=2; i<=M; ++i){
			a/=i;
			if(i%2==0)
				sum+=a;
			else
				sum-=a;
		}
		cout<<sum/b<<endl;
	}  
	return 0;  
}   