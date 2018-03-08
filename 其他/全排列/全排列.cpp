/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3;
char str[N]; // ‰»Î
string s[N]; //¥Ê¥¢Ω·π˚
int total;

bool isSwap(int k, int m){
	for(int i=k; i<m; i++)
		if(str[m]==str[i])
			return false;
	return true;
}

void perm(int k, int m){
	if(k==m){
		s[total++] = str;
		return;
	}
	for(int i=k; i<=m; i++){
		if(isSwap(k,i)){
			swap(str[k],str[i]);
			perm(k+1,m);
			swap(str[k],str[i]);
		}
	}
}

int main() {
	while (~scanf("%s",str)) {
		int len = strlen(str);
		total = 0;
		perm(0, len-1);
		sort(s, s+total);
		for(int i=0; i<total; i++)
			cout<<s[i]<<endl;
		printf("Total %d\n", total);
	}
	return 0;
}
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3;
char str[N], buf[N];//buffer
int vis[N], total, len;
void arrange(int num) {
	if (num == len){
		printf("%s\n", buf);
		total++;
		return;
	}
	for (int i = 0; i < len; ++i) {
		if (!vis[i]) {
			int j;
			for (j = i + 1; j < len; ++j) {
				if (vis[j] && str[i]==str[j]) {
					break;
				}
			}
			if (j == len) {
				vis[i] = 1;
				buf[num] = str[i];
				arrange(num + 1);
				vis[i] = 0;
			}
		}
	}
}
int main() {
	while (~scanf("%s",str)) {
		len = strlen(str);
		sort(str, str + len);
		total = 0;
		buf[len] = '\0';
		arrange(0);
		printf("Total %d\n", total);
	}
	return 0;
}