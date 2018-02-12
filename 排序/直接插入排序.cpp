#include <iostream>
#include <vector>
using namespace std;

vector<int> insertSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}
	result = list;
	// 第1个数肯定是有序的，从第2个数开始遍历，依次插入有序序列
	for (int i = 1; i < result.size(); i++){
		// 取出第i个数，和前i-1个数比较后，插入合适位置
		int temp = result[i];
		// 因为前i-1个数都是从小到大的有序序列，所以只要当前比较的数(list[j])比temp大，就把这个数后移一位
		int j;
		for (j=i-1; j >= 0 && result[j] > temp; j--){
			result[j + 1] = result[j];
		}
		result[j + 1] = temp;
		cout << "第"<<i<<"轮:";
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
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = insertSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}