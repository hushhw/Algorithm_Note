#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp){
	int i=left;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=right){
		if(input[i]<=input[j]){
			temp[k++] = input[i++];
		} else {
			temp[k++] = input[j++];
		}
	}
	while(i<=mid)
		temp[k++]=input[i++];
	while(j<=right)
		temp[k++]=input[j++];
	k=0;
	while(left<=right){
		input[left++] = temp[k++];
		cout<<input[left-1]<<" ";
	}
	cout<<endl;
}

void MergeSort(vector<int> &input, int left, int right, vector<int> temp){
	if(left<right){
		int mid = (left+right)>>1;
		MergeSort(input, left, mid, temp);
		MergeSort(input, mid+1, right, temp);
		Merge(input, left, mid ,right, temp);
	}
}

int main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1};
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	vector<int> temp(result.size());// 在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
	MergeSort(result, 0, result.size()-1, temp);

	cout << "排序后:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}