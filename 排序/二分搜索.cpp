#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000+10;

void solve(){
	int a[]={1,3,8,11,13,19,20,23,39};
	int n = 9, k = 14;
	int lb = 0, ub = n;

	//重复循环，知道解的存在范围不大于1
	while(ub - lb > 0){
		int mid = (lb+ub)/2;
		if(a[mid]>k)
			ub = mid;
		else if(a[mid]<k)
			lb = mid;
		else {
			cout<<mid<<endl;
			break;
		}
	}
}

void stl_solve(){
	int a[] = { 1, 3, 8, 11, 14, 19, 20, 23, 39 };

	int loc = lower_bound(a, a + 9, 14) - a;
	cout << loc << endl;
}

int main(){
	solve(); //手写
	stl_solve(); //使用lower_bound
	system("pause");
	return 0;
}