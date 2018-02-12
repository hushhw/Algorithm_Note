#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long f[22];  
void init()//¥Ì≈≈  
{  
	f[1]=0;  
	f[2]=1;  
	for(int i=3;i<=20;i++)  
	{  
		f[i]=(i-1)*(f[i-1]+f[i-2]);  
	}  
	return ;  
}  

int c(int x, int y){  
	int n=x, m=y;
	int sum=1,a=1,b=1;  
	for(int i=1;i<=y;i++)  {  
		a*=n;  
		n--; 
		b*=m;  
		m--; 
	}  
	sum=a/b;  
	return sum;
}

int main(){  
	int N,M;  
	init();  
	while(scanf("%d%d",&N,&M)!=EOF)  
	{  
		
		cout<<c(N,M)*f[M]<<endl;  
	}  
	return 0;  
}   