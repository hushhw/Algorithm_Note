#include <iostream>
#include <vector>
using namespace std;

void HeapAdjust(vector<int> &list, int start, int length){
	int parent = start;			//父节点
	int child = 2 * parent + 1;	// 先获得左孩子
	
	while (child <= length){	
		// 如果有右子节点，并且右子节点的值大于左子节点，则选取右子节点，否则选取左节点
		if (child + 1 <= length && list[child] < list[child + 1]){
			child++;
		}
		//如果父节点大于孩子节点则代表调整完毕，直接跳出函数
		if (list[parent] > list[child]){
			break;
		}
		else{ //否则交换父子内容再继续子节点和孙节点比较
			swap(list[parent], list[child]);
			parent = child;//父更新为子节点位置
			child = parent*2+1;//子节点更新为孙节点位置
		}
	}
}

vector<int> HeadSort(vector<int> list){
	int length = list.size();
	// 循环建立初始堆，i从最后一个父节点开始
	for (int i = length/2-1; i >= 0; i--){
		HeapAdjust(list, i, length-1);
	}
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " ";
	}
	cout << endl;
	// 进行n-1次循环，完成排序
	for (int i = length - 1; i > 0; i--){
		// 最后一个元素和第一元素进行交换
		swap(list[0], list[i]);

		// 筛选 R[0] 结点，得到i-1个结点的堆
		HeapAdjust(list, 0, i-1);
		cout << "第" << length - i << "趟排序:";
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
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = HeadSort(test);
	cout << "排序后:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}