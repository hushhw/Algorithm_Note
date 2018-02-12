#include <iostream>
#include <vector>
using namespace std;

void HeapAdjust(vector<int> &list, int start, int length){
	int parent = start;			//���ڵ�
	int child = 2 * parent + 1;	// �Ȼ������
	
	while (child <= length){	
		// ��������ӽڵ㣬�������ӽڵ��ֵ�������ӽڵ㣬��ѡȡ���ӽڵ㣬����ѡȡ��ڵ�
		if (child + 1 <= length && list[child] < list[child + 1]){
			child++;
		}
		//������ڵ���ں��ӽڵ�����������ϣ�ֱ����������
		if (list[parent] > list[child]){
			break;
		}
		else{ //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
			swap(list[parent], list[child]);
			parent = child;//������Ϊ�ӽڵ�λ��
			child = parent*2+1;//�ӽڵ����Ϊ��ڵ�λ��
		}
	}
}

vector<int> HeadSort(vector<int> list){
	int length = list.size();
	// ѭ��������ʼ�ѣ�i�����һ�����ڵ㿪ʼ
	for (int i = length/2-1; i >= 0; i--){
		HeapAdjust(list, i, length-1);
	}
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " ";
	}
	cout << endl;
	// ����n-1��ѭ�����������
	for (int i = length - 1; i > 0; i--){
		// ���һ��Ԫ�غ͵�һԪ�ؽ��н���
		swap(list[0], list[i]);

		// ɸѡ R[0] ��㣬�õ�i-1�����Ķ�
		HeapAdjust(list, 0, i-1);
		cout << "��" << length - i << "������:";
		for (int i = 0; i < list.size(); i++){
			cout << list[i] << " ";
		}
		cout << endl;
	}
	return list;
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = HeadSort(test);
	cout << "�����:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}