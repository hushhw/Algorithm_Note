#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	for(int i=0; i < result.size()-1; ++i){		//���ѭ�����������
		cout<<"��"<<i+1<<"������:"<<endl;
		/*----------ð�������Ż�����1-----------*/
		bool bChanged = false;	//�������
		/*----------ð�������Ż�����1-----------*/
		for(int j=0; j < result.size()-1; j++){	//�ڲ�ѭ�������������ݽ���
			if(result[j+1] < result[j]){
				swap(result[j+1], result[j]);
				/*----------ð�������Ż�����2-----------*/
				bChanged = true;
				/*----------ð�������Ż�����2-----------*/
			}
			cout<<"������:";
			for(int s=0; s<result.size(); s++){
				cout<<result[s]<<" ";
			}
			cout<<endl;
		}
		/*----------ð�������Ż�����3-----------*/
		if(bChanged == false)	//�����־Ϊfalse,˵�����ֱ���û�н������ݽ�������˵���Ѿ�����
			break;
		/*----------ð�������Ż�����3-----------*/
		cout<<"������:";
		for(int s=0; s < result.size(); s++){
			cout<<result[s]<<" ";
		}
		cout<<endl;
	}
	return result;
}

int main(){
	int arr[] = { 6, 4, 8, 1, 2, 3, 9 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
