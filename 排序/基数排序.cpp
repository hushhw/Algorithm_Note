#include <iostream>
#include <vector>
using namespace std;

// ����������������λ���ĺ���
int MaxBit(vector<int> input){
	// �������ֵ
	int max_data = input[0];
	for (int i = 1; i < input.size(); i++){
		if (input[i] > max_data){
			max_data = input[i];
		}
	}
	cout<<"max_data:"<<max_data<<endl;
	// �������ֵ��λ��
	int bits_num = 0;
	while (max_data){
		bits_num++;
		max_data /= 10;
	}
	cout<<"bits_num:"<<bits_num<<endl;
	return bits_num;
}

vector<int> RadixSort(vector<int> input, int n){
	vector<int> bucket(n);	//�洢��������е�����
	vector<int> count(10);	//λ���������ӵ�0��Ԫ�ص���9��Ԫ������������¼��ǰ�Ƚ�λ��0���ж��ٸ�...��9���ж��ٸ���
	int bits_num = MaxBit(input); //����������������λ���ĺ���
	int radix = 1;
	// �ӵ�λ����λѭ��
	for (int d = 1; d <= bits_num; d++){ 
		// ��������0
		for (int i = 0; i < 10; i++){
			count[i] = 0;
		}
 
		// ͳ�Ƹ���Ͱ�еĸ���
		for (int i = 0; i < n; i++){
			int k=(input[i]/radix)%10;//ȡÿ�����ֵ�ĩβ
			count[k]++;
		}
		cout<<"before:";
		for (int i = 0; i < n; i++){
			cout<<count[i]<<" ";
		}
		cout<<endl;
 
		cout<<"after:   ";
		//�����ط���
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];//count[i]��ʾ��i��Ͱ���ұ߽�����
			cout<<count[i]<<" ";
		}
		cout<<endl;

		//������ʱ���飬���ҵ���ɨ�裬��֤�����ȶ���
		for (int i = n - 1; i >= 0; i--){
			int k = (input[i]/radix)%10;
			bucket[count[k] - 1] = input[i];
			count[k]--;
		}
		cout<<"input:";
		// ��ʱ���鸴�Ƶ� input ��
		for (int i = 0; i < n; i++){
			input[i] = bucket[i];
			cout<<input[i]<<" ";
		}
		cout<<endl;
		radix *= 10;
	}
 
	return input;
}

int main(){
	int arr[] = { 50, 123, 543, 187, 49, 30, 0, 2, 11, 100 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	result = RadixSort(result, result.size());

	cout << "�����:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}