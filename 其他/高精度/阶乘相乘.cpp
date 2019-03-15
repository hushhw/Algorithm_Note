/*
问题描述
　　输入一个正整数n，输出n!的值。
  　　其中n!=1*2*3*…*n。
	算法描述
	　n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
	  将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
	  首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
输入格式
	输入包含一个正整数n，n<=1000。
输出格式
	输出n!的准确值。
样例输入
	10
样例输出
	3628800
*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int N = 11;
int a[10001]; //保存结果

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(a, 0, sizeof(a));
		int i;		//阶乘每一项
		int j;		//结果的每一位
		int w=0;	//用来判断进位
		int t=1;	//保存十位
		for(i=1; i<=n; i++){
			for(j=0; j<=w; j++){
				a[j] = a[j]*i + t;
				t = a[j]/10;
				a[j] = a[j]%10;
				if(j==w && t!=0){
					w++;
				}
			}
		}
		for(int i=w; i>=0; i--){
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}