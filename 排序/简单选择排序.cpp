#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectSort(vector<int> list){
	vector<int> result;
	result = list;
	for(int i=0; i<result.size(); i++){
		int index = i;		//��ǵ�һ��λ��
		for(int j=i+1; j<result.size(); j++){
			if(result[index] > result[j])
				index = j;	//�����indexλ���ϵ�����С���ͱ�Ǹ�����
		}
		swap(result[i], result[index]);	//ѭ��������ѱ�ǵ���С��������λ��index��iλ�ý���
		
		cout << "��" << i + 1<< "��:\t";
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = SelectSort(test);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}