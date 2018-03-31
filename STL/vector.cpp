/*
vector ����һ�� ���������顣����һЩ���õĲ��� ����װ�� ����vector�����ڲ���

vector��һ��ģ���࣬������Ҫvector<int> a ���� vector<string> b �����ķ�ʽ������һ�� vector����

vector<int> ������ int a[] ����������, ��vector<string> b �൱�� string b[] ���ַ������顣

�����ô�����ܣ����õĲ���:
*/
#include <iostream>
#include <vector>		//ʹ��vector��Ҫ�������ͷ�ļ�
#include <iterator>		//������
#include <algorithm>
using namespace std;

void PrintVector(vector<int> c){
	cout << "Vector�е�����Ϊ��";
	vector<int>::iterator vIter; //������
	for (vIter = c.begin(); vIter < c.end(); vIter++){
		cout << *vIter << " "; 
	}
	cout << endl;
}

int main(){
	/* --------------1.vector�Ĵ���------------------ */
	vector<int> v;		//����һ��int���͵�vector����
	vector<int> v2(10);	//����һ��int���͵�vector����������������10��intԪ�أ�ÿ��Ԫ�ر�����ʼֵΪ0
	vector<int> v3(5,99);//����һ��int���͵�vector��������������5��intԪ�أ�ÿ��Ԫ�ر���ֵ99
	vector<int> v4(v2);	//����һ��int���͵�vector����������������v2������������10��ֵΪ0��Ԫ�ء�

	/* -----2.push_back(),pop_back()���ɾ��Ԫ��------ */
	int A[10]={9,5,8,6,4,2,3,7,0,1};
	for(int i=0;i<10;i++){
		v.push_back(A[i]);	//��v��β��ѭ������Ԫ��
	}
	v.pop_back(); //��v��β��ɾ��Ԫ��
	// ��vectorͷ�����Ԫ�أ��޷���ɣ���Ϊvector�����ݽṹΪ���飬�޷���ͷ������Ԫ�أ�������Ҫ��������ǰ�ƣ�  
	// ��vectorͷ��ɾ��Ԫ�أ��޷���ɣ�����ͬ�ϡ�

	/* ----------3.[],at(),ȡĳλ�õ�Ԫ��ֵ----------- */
	cout<<"��0λ�õ�Ԫ��ֵΪ��"<<v.at(0)<<endl;
	cout<<"��1λ�õ�Ԫ��ֵΪ��"<<v[1]<<endl;

	/* ----4.begin(),end(),ָ��ͷԪ�ء�βԪ�ص�ָ��---- */
	//sort(v.begin(), v.end()); sort��ʱ�򾭳��õ�
	vector<int>::iterator vIter; //������
	for (vIter = v.begin(); vIter < v.end(); vIter++){
		cout << *vIter << " "; 
	}
	cout << endl;

	/* ----5.back(),front(),����ͷ��Ԫ�غ�β��Ԫ��---- */
	// ����β�����ݵ�����
	cout << "β�����ݵ�ֵΪ��" << v.back() << endl;
	// ����ͷ�����ݵ�����
	cout << "ͷ�����ݵ�ֵΪ��" << v.front() << endl;

	/* -----------6.max_size()��size()------------- */
	cout << "vector�е��������Ϊ��" << v.max_size() << endl;
	cout << "vector�е�Ԫ�ظ���Ϊ��" << v.size() << endl;

	/* ----------7.empty()���ж��Ƿ�Ϊ��------------ */
	cout << "vector�Ƿ�Ϊ�գ�" << v.empty() << endl;

	/* ----------8.swap(),��������Ԫ��λ��------------ */
	swap(v[0],v[1]);
	PrintVector(v);

	/* -------------9.sort()��reverse()------------- */
	// ��vector������������
	sort(v.begin(), v.end());
	PrintVector(v);
	// ��vector���н�������
	reverse(v.begin(), v.end());
	PrintVector(v);

	/* ----------10.erase()��ɾ��ĳ��Ԫ��----------- */
	// ɾ�������ĳ��Ԫ��
	// ΪʲôҪʹ��iterator�����ж�λ����Ϊ�������Ҫɾ��һ��Ԫ�ػ��߲���һ��Ԫ�أ��ᵼ������Ԫ���ƶ������Բ���ֱ�ӽ���ɾ��
	vector<int>::iterator vItera = v.begin();
	vItera = vItera + 2;
	v.erase(vItera);
	PrintVector(v);

	/* ----------11.insert(): ����Ԫ��------------ */
	// vector����ĳԪ�أ�Ҫʹ��iterator����λĳ��λ��
	vector<int>::iterator vInsert = v.begin();
	vInsert = vInsert + 2;
	v.insert(vInsert, 777);
	PrintVector(v);

	/* ---------12.clear()���������Ԫ��------------*/
	// �����������
	v.clear();
	PrintVector(v);
	cout << "vector�Ƿ�Ϊ�գ�" << v.empty() << endl;

	system("pause");
	return 0;
}