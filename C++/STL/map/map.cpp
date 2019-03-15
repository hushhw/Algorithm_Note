#include <iostream>
#include <map>
#include <iterator>		//迭代器
using namespace std;

int main(){
    /* --------------1.map的声明及迭代器声明------------------ */
    map<string, string> mapStudent;
    map<string, string>::iterator iter;
    map<string, string>::reverse_iterator iter_r;


    /* --------------2.map插入数据------------------ */
    //用insert函数插入pair数据
    mapStudent.insert(pair<string, string>("r000", "student_zero"));

    //用insert函数插入value_type数据
    mapStudent.insert(map<string, string>::value_type("r001", "student_one"));

    //用数组方式插入数据
    mapStudent [ "r123" ] =  "student_first" ;
    mapStudent [ "r456" ] =  "student_second" ;

    /* --------------3.map的大小------------------ */
    int nsize = mapStudent.size();

    /* --------------4.map的遍历------------------ */
    //traversal
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
                cout<<iter->first<<" "<<iter->second<<endl;
    for(iter_r = mapStudent.rbegin(); iter_r != mapStudent.rend(); iter_r++)
                cout<<iter_r->first<<" "<<iter_r->second<<endl;

    /* --------------5.map的查找------------------ */
    iter = mapStudent.find("r123");

    if(iter != mapStudent.end())
       cout<<"Find, the value is "<<iter->second<<endl;
    else
       cout<<"Do not Find"<<endl;
    
    /* --------------6.map删除元素------------------ */
    //迭代器删除
    iter = mapStudent.find("r123");
    mapStudent.erase(iter);

    //用关键字删除
    int n = mapStudent.erase("r123");//如果删除了會返回1，否則返回0

    //用迭代器范围删除 : 把整個map清空
    mapStudent.erase(mapStudent.begin(), mapStudent.end());
    //等同於mapStudent.clear()

    return 0;
}