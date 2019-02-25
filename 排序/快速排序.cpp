#include <iostream>
#include <vector>
using namespace std;

int division(vector<int> &list, int left, int right){
	int base = list[left];
	while(left < right){
		while(left < right && list[right]>=base)//从序号右端开始向左遍历，直到找到小于base的数
			right--;
		list[left] = list[right];	//找到比base小的元素，将这个元素放到最左边的位置
		while(left < right && list[left]<=base) //从序号左端开始向右遍历，直到找到大于base的数
			left++;
		list[right] = list[left];	//找到比base大的元素，将这个元素放到最右边的位置
	}

	list[left] = base;
	cout << "每一轮：";
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " ";
	}
	cout<<endl;
	return left;
}

void QuickSort(vector<int> &list, int left, int right){
	if(left < right){	//左下标一定小于右下标，否则越界
		int base = division(list, left, right);//对数组进行分割，去除下次分割的基准标号
		QuickSort(list, left, base-1);//左
		QuickSort(list, base+1, right);//右
	}
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1};
	vector<int> test(arr, arr + sizeof(arr)/sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result = test;

	QuickSort(result, 0, result.size() - 1);

	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}