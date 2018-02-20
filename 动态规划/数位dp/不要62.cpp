/*
Problem Description
�����˳���Щɵ����ճ�વ���Ϊ62������laoer����
���ݽ�ͨ����־���������һЩ��ʿ�����գ��½�����һ������Ϣ���Ժ������գ����ٺ��в������������ˣ�����һ�����Ϳ������������ʿ˾���ͳ˿͵������ϰ�������ȫ�ط�����ڡ�
������������Ϊ���к���4��62�ĺ��롣���磺
62315 73418 88914
�����ڲ��������롣���ǣ�61152��Ȼ����6��2��������62���ţ����Բ����ڲ���������֮�С�
��������ǣ�����ÿ�θ�����һ����������ţ��ƶϳ����ֽܾ����Ҫʵ���ϸ��������µ�ʿ���������ˡ�

Input
����Ķ���������n��m��0<n��m<1000000���������������0�������ԣ������������

Output
����ÿ�������ԣ����һ�������в��������ֵ�ͳ�Ƹ���������ֵռһ��λ�á�

Sample Input
1 100 0 0

Sample Output
80

Author
qianneng
Source
ӭ����ѧ�ڡ�������Easy��������

���⣺

����[l,r]�����ֵ���λ����62�Ҳ���4�����ĸ���

*/
/*
#include <iostream>
#include <string>
using namespace std;

int dp[10][10];

void init(){
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=1; i<=7; i++){		
		for(int j=0; j<10; j++){	//ö�ٵ�iλ���ϵ�����
			for(int k=0; k<10; k++){//ö�ٵ�i-1Ϊ���ϵ�����
				if(j!=4 && !(j==6 && k==2))//��������
					dp[i][j] += dp[i-1][k];
			}
		}
	}
}

int solve(int n){
	init();
	int digit[10];			//�洢ÿλ����
	int len = 1;			//λ��
	while(n){
		digit[len++]=n%10;
		n /= 10;
	}
	int ans=0;				//��¼���������Ľ��
	for(int i=len; i>=1; i--){	//�����Ϊ��ʼ����
		for(int j=0; j<digit[i]; j++){
			if(j!=4 && !(digit[i+1]==6 && j==2))
				ans += dp[i][j];
		}
		if(digit[i]==4 || (digit[i+1]==6 && digit[i]==2)) ////��iλ�Ѿ���������������iλ�Ժ󶼲�������������������ѭ��  
			break;
	}
	return ans;
}

int main(){
	int l,r;
	while(cin>>l>>r){
		if(l+r==0)
			break;
		else
			cout<<solve(r+1)-solve(l)<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;

int dp[10][2]; //dp[i][j]��ʾ����ǰ��iλ��ǰһλ�Ƿ���6��״̬
int a[20];
int l,r,tot;

//pos��ʾ��ǰλ�ã�pre��ʾǰһ������sta��ʾ��ǰ״̬��Ҳ����֮ǰ�Ƿ�Ϊ6
//lim��ʾ��ǰ�Ƿ��������Ƶģ�����967�������ǵ�һ����ѡ��9ʱ���ڶ�������ֻ��ѡ��0-6��
int dfs(int pos, int pre, int sta, int lim){
	int cur=0;
	if(pos==0) return 1; //���ִ�е�0�ˣ���ǰ���ɵ�������
	if(!lim && dp[pos][sta]!=-1) return dp[pos][sta];
	int up = lim? a[pos]:9; //�Ƿ��������ж�
	for(int i=0; i<=up; i++){
		if(i==4 || (pre==6 && i==2)) //�����ǰ����Ϊ4������ǰһ������Ϊ6����ǰλ2���ų�
			continue;
		cur += dfs(pos-1, i, i==6, lim&&i==a[pos]);
	}
	if(!lim) dp[pos][sta]=cur;
	return cur;
}

int solve(int x){
	tot = 0;	//tot������¼λ��
	while(x){
		a[++tot]=x%10;
		x /= 10;
	}
	return dfs(tot,-1,0,1);
}

int main(){
	while(~scanf("%d%d",&l,&r)&&(l+r)){
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(r)-solve(l-1));
	}
	return 0;
}
