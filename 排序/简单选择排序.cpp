#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectSort(vector<int> list){
	vector<int> result;
	result = list;
	for(int i=0; i<result.size(); i++){
		int index = i;		//标记第一个位置
		for(int j=i+1; j<result.size(); j++){
			if(result[index] > result[j])
				index = j;	//如果比index位置上的数字小，就标记该数字
		}
		swap(result[i], result[index]);	//循环结束后把标记的最小数字所在位置index和i位置交换
		
		cout << "第" << i + 1<< "趟:\t";
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
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = SelectSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}