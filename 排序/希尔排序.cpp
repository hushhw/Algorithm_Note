#include <iostream>
#include <vector>

using namespace std;

vector<int> ShellSort(vector<int> list){
	vector<int> result;
	result = list;
	int n = result.size();
	for(int gap = n >> 1; gap > 0; gap >>= 1){	//��n���ж��ֳ�������
		for(int i=gap; i<n; i++){
			int temp = result[i];	//��¼i���ڵ���
			int j;
			for(j = i-gap; j>=0 && result[j]>temp; j -= gap){//�����Ϊgap��i,j�������ֱȽϣ��൱�ڸ����ж�
				result[j+gap] = result[j];
			}
			result[j+gap] = temp;
		}
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
	result = ShellSort(test);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}