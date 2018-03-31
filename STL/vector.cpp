/*
vector 就是一个 不定长数组。它把一些常用的操作 “封装” 在了vector类型内部。

vector是一个模板类，所以需要vector<int> a 或者 vector<string> b 这样的方式来声明一个 vector对象。

vector<int> 类似于 int a[] 的整数数组, 而vector<string> b 相当于 string b[] 的字符串数组。

下面用代码介绍，常用的操作:
*/
#include <iostream>
#include <vector>		//使用vector需要引用这个头文件
#include <iterator>		//迭代器
#include <algorithm>
using namespace std;

void PrintVector(vector<int> c){
	cout << "Vector中的数据为：";
	vector<int>::iterator vIter; //迭代器
	for (vIter = c.begin(); vIter < c.end(); vIter++){
		cout << *vIter << " "; 
	}
	cout << endl;
}

int main(){
	/* --------------1.vector的创建------------------ */
	vector<int> v;		//创建一个int类型的vector容器
	vector<int> v2(10);	//创建一个int类型的vector容器，该容器暂有10个int元素，每个元素被赋初始值为0
	vector<int> v3(5,99);//创建一个int类型的vector容器，该容器有5个int元素，每个元素被赋值99
	vector<int> v4(v2);	//创建一个int类型的vector容器，该容器拷贝v2，该容器具有10个值为0的元素。

	/* -----2.push_back(),pop_back()添加删除元素------ */
	int A[10]={9,5,8,6,4,2,3,7,0,1};
	for(int i=0;i<10;i++){
		v.push_back(A[i]);	//在v的尾部循环插入元素
	}
	v.pop_back(); //在v的尾部删除元素
	// 在vector头部添加元素，无法完成，因为vector的数据结构为数组，无法在头部插入元素，否则需要整个数组前移；  
	// 在vector头部删除元素，无法完成，理由同上。

	/* ----------3.[],at(),取某位置的元素值----------- */
	cout<<"在0位置的元素值为："<<v.at(0)<<endl;
	cout<<"在1位置的元素值为："<<v[1]<<endl;

	/* ----4.begin(),end(),指向头元素、尾元素的指针---- */
	//sort(v.begin(), v.end()); sort的时候经常用到
	vector<int>::iterator vIter; //迭代器
	for (vIter = v.begin(); vIter < v.end(); vIter++){
		cout << *vIter << " "; 
	}
	cout << endl;

	/* ----5.back(),front(),访问头部元素和尾部元素---- */
	// 返回尾部数据的引用
	cout << "尾部数据的值为：" << v.back() << endl;
	// 返回头部数据的引用
	cout << "头部数据的值为：" << v.front() << endl;

	/* -----------6.max_size()和size()------------- */
	cout << "vector中的最大容量为：" << v.max_size() << endl;
	cout << "vector中的元素个数为：" << v.size() << endl;

	/* ----------7.empty()，判断是否为空------------ */
	cout << "vector是否为空：" << v.empty() << endl;

	/* ----------8.swap(),交换两个元素位置------------ */
	swap(v[0],v[1]);
	PrintVector(v);

	/* -------------9.sort()和reverse()------------- */
	// 对vector进行升序排序
	sort(v.begin(), v.end());
	PrintVector(v);
	// 对vector进行降序排序
	reverse(v.begin(), v.end());
	PrintVector(v);

	/* ----------10.erase()：删除某个元素----------- */
	// 删除数组的某个元素
	// 为什么要使用iterator来进行定位，因为数组如果要删除一个元素或者插入一个元素，会导致其他元素移动，所以不能直接进行删除
	vector<int>::iterator vItera = v.begin();
	vItera = vItera + 2;
	v.erase(vItera);
	PrintVector(v);

	/* ----------11.insert(): 插入元素------------ */
	// vector插入某元素，要使用iterator来定位某个位置
	vector<int>::iterator vInsert = v.begin();
	vInsert = vInsert + 2;
	v.insert(vInsert, 777);
	PrintVector(v);

	/* ---------12.clear()：清除所有元素------------*/
	// 清除所有数据
	v.clear();
	PrintVector(v);
	cout << "vector是否为空：" << v.empty() << endl;

	system("pause");
	return 0;
}