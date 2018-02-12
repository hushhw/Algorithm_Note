#include <iostream>
#include <vector>
using namespace std;

vector<int> insertSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}
	result = list;
	// ��1�����϶�������ģ��ӵ�2������ʼ���������β�����������
	for (int i = 1; i < result.size(); i++){
		// ȡ����i��������ǰi-1�����ȽϺ󣬲������λ��
		int temp = result[i];
		// ��Ϊǰi-1�������Ǵ�С������������У�����ֻҪ��ǰ�Ƚϵ���(list[j])��temp�󣬾Ͱ����������һλ
		int j;
		for (j=i-1; j >= 0 && result[j] > temp; j--){
			result[j + 1] = result[j];
		}
		result[j + 1] = temp;
		cout << "��"<<i<<"��:";
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

void main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = insertSort(test);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}