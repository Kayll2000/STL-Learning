/**
* @author [chenjunlong]
* @version [v1.0, 2023-03-01]
* @see [STL]
* @container array
* @since [v1]
* @deprecated array[序列容器]长度不可扩展和收缩
*/
#include <iostream>
#include <array>

using namespace std;
#define N 10

void IterFun(array<int,N> ver)
{
    int i = 0;
    if(!ver.empty())
    {
        for(auto it = ver.begin();it!=ver.end();it++,i++)
        {
            cout<<"ver["<<i<<"] = "<<*it<<endl;
        }
    }else{
        cout<<"ver is empty!"<<endl;
    }
}
int main()
{
    array<int,N> data;
    array<int,N> data2 {1,2,3,4,5};
    //at(n)	返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常
    for(int i = 0;i < N;i++)
    {
        data.at(i) = i;
    }
    //使用 get() 重载函数输出指定位置元素
    cout <<"第四个元素 "<< get<3>(data) << endl;
    cout<<"data size  "<<data.size()<<endl;
    cout<<"data maxsize  "<<data.max_size()<<endl;
    cout<<"data2 size "<<data2.size()<<endl;
    IterFun(data);
}