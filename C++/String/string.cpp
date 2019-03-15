#include <iostream>
#include <string>
using namespace std;

int main(){
    /* --------------1.string声明创建------------------ */
    string str("hello C++");
    string sh(" C++");
    string s;

    /* --------------2.字符串赋值操作------------------ */
    s = s.assign(str);
    s = s.assign(5, 'x'); //把5个x赋给字符串
    s = s.assign(str, 6, 3);
    cout << str << endl
         << s << endl;
    s = s.assign("hello STL", 0, 6);
    cout << s << endl<<endl;

    /* --------------3.在尾部添加字符------------------ */
    //+=,append(),push_back()
    s += str;
    s.append(sh);
    s.append(str, 5, 4);
    s.append("hello STL", 5, 4);
    s.append(5, 'x');
    s.push_back('a');
    cout << s << endl<<endl;

    /* --------------4.insert()------------------ */
    s.insert(0, "hello ");
    s.insert(0, str, 0, 6);
    s.insert(0, "that is cool",8);
    s.insert(7, 1, ':');
    cout << s << endl<<endl;

    /* --------------5.erase()------------------ */
    s.erase(9, 18); //删除三个"hello "
    cout << s << endl<<endl;

    /* --------------6.replace()------------------ */
    s.replace(15, 3, str, 0, 5);
    s.replace(25, 3, "C++ Primer Plus", 4, 11);
    cout << s << endl<<endl;

    /* --------------7.子串substr()------------------ */
    string hello = s.substr(9, 5);
    cout << hello << endl<< endl;

    /* --------------8.查找------------------ */
    if(s.find(hello) != string::npos){
        cout<<"'hello' found at:"<<s.find(hello)<<endl;
    }

    system("pause");
    return 0;
}