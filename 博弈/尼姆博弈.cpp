/*
 *	ÄáÄ·²©ŞÄ
 */

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int m,n,g,sum=0;
		cin>>g;
		while(g--){
			cin>>m>>n;
			sum ^= m%(n+1);
		}
		cout<<(sum? "Win":"Lose")<<endl;
	}
	system("pause");
	return 0;
}