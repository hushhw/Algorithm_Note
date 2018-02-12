#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	for(int i=0; i < result.size()-1; ++i){		//外层循环仅标记趟数
		cout<<"第"<<i+1<<"趟排序:"<<endl;
		/*----------冒泡排序优化代码1-----------*/
		bool bChanged = false;	//交换标记
		/*----------冒泡排序优化代码1-----------*/
		for(int j=0; j < result.size()-1; j++){	//内层循环进行相邻数据交换
			if(result[j+1] < result[j]){
				swap(result[j+1], result[j]);
				/*----------冒泡排序优化代码2-----------*/
				bChanged = true;
				/*----------冒泡排序优化代码2-----------*/
			}
			cout<<"排序中:";
			for(int s=0; s<result.size(); s++){
				cout<<result[s]<<" ";
			}
			cout<<endl;
		}
		/*----------冒泡排序优化代码3-----------*/
		if(bChanged == false)	//如果标志为false,说明本轮遍历没有进行数据交换，即说明已经有序
			break;
		/*----------冒泡排序优化代码3-----------*/
		cout<<"排序结果:";
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
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
