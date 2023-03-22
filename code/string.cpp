/**
 * @version [v1.0, 2023-02-28]
 * @see [STL]
 * @container string
 * @since [v1]
 * @deprecated string 本质为一个类  其内部维护了一个char* 指针
 * @author [chenjunlong]
*/
#include <iostream>
#include <string>

using namespace std;

void fun(string str)
{
    auto it = str.begin();
    for(it;it != str.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void fun2(string _str)
{
    cout << "_str 值为" << _str << endl;
}
void Info(string str)//str 信息
{
    cout << "str 长度："<< str.length()<< endl;
    cout << "str 大小："<< str.size() << endl;
    cout << "str 容量："<< str.capacity()<< endl;
    
}
int main()
{
    const char* s = "hello";
    //构造
    string str1;// 定义 string 容器
    string str1_0;
    string str1_1;
    string str1_2;
    string str2(s);
    string str3("hello");//将hello复制给str3
    string str3_{"hello"};//给str3_赋值hello
    string str4(str3);
    string str5(5,'A');
    //赋值
    str1 = "love";
    str1_0 = str1;
    str1_1 = 'L';
    
    /*
    a.assign(b,begin,len);
    从字符串b的第(begin)个字符开始向后数(len)个字符(包括begin)的字符串赋值给字符串a
    */
    string a = "abc";
    string b = "123";
    fun2(a);
    fun2(b);
    a.assign(b);//等价 a = b;  结果：a = "123"
    fun2(a);
    a.assign("456");//a = "456"
    fun2(a);
    a.assign(b,0,1);//从b的第0个开始，往后数1个字符并赋值给a
    fun2(a);
    a.assign(b,1,1);
    fun2(a);
    a.assign(b,1,2);
    fun2(a);
    a.push_back('a');
    fun2(a);
    Info(a);
    
    fun(str1);      fun(str1_0);
    fun(str1_1);    fun(str1_2);
    fun(str2);      fun(str3);
    fun(str5);
    
    return 0;
}
/*
运行结果：
        _str 值为abc
        _str 值为123
        _str 值为123
        _str 值为456
        _str 值为1
        _str 值为2
        _str 值为23
        _str 值为23a
        str 长度：3
        str 大小：3
        str 容量：15
        l o v e 
        l o v e 
        L 
        
        h e l l o 
        h e l l o 
        A A A A A 
*/