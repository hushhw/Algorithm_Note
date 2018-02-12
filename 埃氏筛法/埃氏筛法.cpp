#include <iostream>
#include <cstdio>
using namespace std;
const int SIZE = 1e7;

int prime[SIZE];		//��i������
bool is_prime[SIZE];	//true��ʾi������

int slove(int n){
	int p=0;
	for(int i=0; i<=n; i++)
		is_prime[i] = true;		//��ʼ��
	is_prime[0] = is_prime[1] = false;	//0,1��������

	for(int i=2; i<=n; i++){
		if(is_prime[i]){
			prime[p++] = i;
			for(int j=2*i; j<=n; j+=i)
				is_prime[j] = false;
		}
	}
	return p;
}

int main(){
	int n;
	while(cin>>n){
		int res = slove(n);
		cout<<res<<endl;
		for(int i=0; i<res; i++)
			cout<<prime[i]<<endl;
	}
}