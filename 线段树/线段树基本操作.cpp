/*
��������
��n�����ӣ������ҷų�һ�ţ����Ϊ1-n��

����m�β�������3�ֲ������ͣ�

1.�޸�һ�����ӵ�Ȩֵ��

2.������һ�θ���Ȩֵ�ͣ�

3.������һ�θ��ӵ����ֵ��

����ÿ��2��3���������������Ľ����

�����ʽ
��һ��2������n��m��

������һ��n��������ʾn�����ӵĳ�ʼȨֵ��

������m�У�ÿ��3������p,x,y��p��ʾ�������ͣ�p=1ʱ��ʾ�޸ĸ���x��ȨֵΪy��p=2ʱ��ʾ������[x,y]�ڸ���Ȩֵ�ͣ�p=3ʱ��ʾ������[x,y]�ڸ�������Ȩֵ��

�����ʽ
�������У���������p=2��3�Ĳ���������

ÿ��1����������Ӧ��ÿ��p=2��3�����Ľ����

��������
4 3
1 2 3 4
2 1 3
1 4 3
3 1 4
�������
6
3
���ݹ�ģ��Լ��
����20%������n <= 100��m <= 200��

����50%������n <= 5000��m <= 5000��

����100%������1 <= n <= 100000��m <= 100000��0 <= ����Ȩֵ <= 10000��
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 100010
using namespace std;

struct node{
	int left,right;//�������ұ߽�
	int sum,max;//Ȩֵ�����ֵ
}a[MAXN*3+1];

int imax(int a,int b){//�жϴ�С�ĺ���   
	return a>b?a:b;
}  

int qMax(int n, int l, int r){	//que=3����l��r���Ȩֵ
	if(l == a[n].left && r == a[n].right)//����Χ�����ҷ�Χ��� ��ֱ��������ֵ   
		return a[n].max;  
	int middle = (a[n].left + a[n].right) / 2;  
	if(r <= middle)  
		return qMax(n*2, l, r);//������Χ�����ӷ�Χ�ڣ�������Ѱ��   
	else if(l > middle)  
		return qMax(n*2+1, l, r);//������Χ���Һ��ӷ�Χ�ڣ����Һ���Ѱ��  
	else   
		return imax(qMax(n*2, l, middle), qMax(n*2+1, middle+1, r));//����Χ�����Һ���֮�䣬�ֱ������ֵ��Ȼ�����������ֵ
}

int qSum(int n, int l, int r){	//que=2������l��r��Ȩֵ��
	if(l==a[n].left && r==a[n].right)	//����Ҷ�ӽڵ㣬������ȣ�ֱ�ӷ���sum
		return a[n].sum;
	
	int middle = (a[n].left+a[n].right)/2;
	if(r <= middle){ //������������
		return qSum(n*2, l, r);//�������ӷ�Χ��������Ѱ��
	} else if(l > middle){
		return qSum(n*2+1, l, r);//�����Һ��ӷ�Χ�����Һ���Ѱ��
	} else	{					//����֮�䣬�ֱ�������
		return (qSum(n*2, l, middle) + qSum(n*2+1, middle+1, r));
	}
}



void change(int n, int l, int r, int num){ 
	//que=1,������[l,r]�н�r��Ȩֵ��Ϊnum������l==r
	if(l==a[n].left && r==a[n].right){		//�±������ҷ�Χ��ȣ��汾��
		a[n].sum = num;
		a[n].max = num;
		return ;
	}

	int middle = (a[n].left+a[n].right)/2;
	if(r<=middle)
		change(n*2, l, r, num);	//��������
	else if(r>middle)
		change(n*2+1, l, r, num);	//�����Һ���
	else{
		change(n*2, l, middle, num);
		change(n*2+1, middle+1, r, num);
	}
	a[n].sum = a[n*2].sum + a[n*2+1].sum;	//�����ܺ�
	a[n].max = imax(a[n*2].max, a[n*2+1].max);	//�������ֵ
}

void build(int n, int l, int r){
	if(l==r){		//������Ҽ�����,˵����Ҷ�ӽڵ�
		a[n].left = l;
		a[n].right = r;
		scanf("%d",&a[n].sum);
		a[n].max = a[n].sum;
		return ;
	}

	int middle = (l+r)/2;
	a[n].left = l;		//��߾�
	a[n].right = r;		//�ұ߾�
	build(n*2, l, middle);	//����l��mid������
	build(n*2+1, middle+1, r);	//����mid+1��r���Һ���

	a[n].sum = a[n*2].sum + a[n*2+1].sum;
	a[n].max = imax(a[n*2].max, a[n*2+1].max);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);	//����һ����ΧΪ1��n���߶���

	int que,b,c;
	while(m--){
		scanf("%d%d%d",&que, &b, &c);
		switch(que){
			case 1:
				change(1,b,b,c); break;//�ı�ڵ�b��ȨֵΪc  
			case 2:
				printf("%d\n", qSum(1,b,c)); break;//����b��c��Χ�ڵ�Ȩֵ��   
			case 3:
				printf("%d\n", qMax(1,b,c)); break;//����b��c��Χ�ڵ����Ȩֵ   
			default: break;
		}
	}
	system("pause");
	return 0;
}