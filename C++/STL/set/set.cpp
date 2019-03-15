#include <iostream>
#include <set>
#include <iterator>		//迭代器
#include <algorithm>
using namespace std;

int main(){
    /* --------------1.set的创建------------------ */
	set<int> v;		//创建一个int类型的set容器
    set<int>::iterator it;     //创建一个他对应的迭代器

	/* -----2.插入元素------ */
	int A[10]={9,5,8,6,4,2,3,7,0,1};
	for(int i=0;i<10;i++){
        v.insert(A[i]);
    }

	/* ----------3.find()查找元素及erase()删除元素----------- */
	it=v.find(9);
    v.erase (it); //输出 0 1 2 3 4 5 6 7 8
    v.erase (v.find(0)); //输出1 2 3 4 5 6 7 8

	/* ----4.返回某个值元素的个数---- */
    for(int i=0;i<10; i++){
        cout << i;
        if (v.count(i)>0) //返回某个值元素的个数
            cout << " is an element of v.\n";
        else 
            cout << " is not an element of v.\n";
    }

	
	/* ----5.lower_bound/upper_bound---- */
	//lower_bound 返回指向首个不小于给定键的元素的迭代器
    //upper_bound 返回指向首个大于给定键的元素的迭代器
    set<int>::iterator itlower, itupper;
    itlower = v.lower_bound(3); //3
    itupper = v.upper_bound(6); //7
    v.erase(itlower, itupper);
    for (it = v.begin(); it != v.end(); it++){
        cout << *it << " "; //输出为 1 2 7 8，删除了3——6
    }
    cout << endl;
    
    system("pause");
    return 0;
}