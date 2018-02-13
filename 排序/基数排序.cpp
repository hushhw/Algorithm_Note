#include <iostream>
#include <vector>
using namespace std;

// 求出数组中最大数的位数的函数
int MaxBit(vector<int> input){
	// 数组最大值
	int max_data = input[0];
	for (int i = 1; i < input.size(); i++){
		if (input[i] > max_data){
			max_data = input[i];
		}
	}
	cout<<"max_data:"<<max_data<<endl;
	// 数组最大值的位数
	int bits_num = 0;
	while (max_data){
		bits_num++;
		max_data /= 10;
	}
	cout<<"bits_num:"<<bits_num<<endl;
	return bits_num;
}

vector<int> RadixSort(vector<int> input, int n){
	vector<int> bucket(n);	//存储排序过程中的数据
	vector<int> count(10);	//位计数器，从第0个元素到第9个元素依次用来记录当前比较位是0的有多少个...是9的有多少个数
	int bits_num = MaxBit(input); //求出数组中最大数的位数的函数
	int radix = 1;
	// 从低位往高位循环
	for (int d = 1; d <= bits_num; d++){ 
		// 计数器清0
		for (int i = 0; i < 10; i++){
			count[i] = 0;
		}
 
		// 统计各个桶中的个数
		for (int i = 0; i < n; i++){
			int k=(input[i]/radix)%10;//取每个数字的末尾
			count[k]++;
		}
		cout<<"before:";
		for (int i = 0; i < n; i++){
			cout<<count[i]<<" ";
		}
		cout<<endl;
 
		cout<<"after:   ";
		//索引重分配
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];//count[i]表示第i个桶的右边界索引
			cout<<count[i]<<" ";
		}
		cout<<endl;

		//放入临时数组，从右到左扫描，保证排序稳定性
		for (int i = n - 1; i >= 0; i--){
			int k = (input[i]/radix)%10;
			bucket[count[k] - 1] = input[i];
			count[k]--;
		}
		cout<<"input:";
		// 临时数组复制到 input 中
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
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	result = RadixSort(result, result.size());

	cout << "排序后:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}