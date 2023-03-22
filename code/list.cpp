/**
* @author [chenjunlong]
* @version [v1.0, 2023-03-01]
* @see [STL]
* @container list
* @since [v1]
* @deprecated 双向链表容器,list 底层是双向链表
*/

#include <list>
#include <iostream>
using namespace std;

#define N 10
/**
 * 正向迭代器遍历容器 API
 */
void IterFun(list<int> ver)
{
    auto it = ver.begin();int i = 0;
    cout<<"ver size is "<<ver.size()<<endl;
    if(!ver.empty())
    {
        for(it;it!=ver.end();it++,i++)
        {
            cout<<"ver["<<i<<"] = "<<*it<<endl;       
        }
    }else
    {
        cout<<"ver is empty"<<endl;
    }
}

int main()
{
    list<int> listdata;
    for(int i = 0;i < N;i++)
    {
        listdata.push_back(i);
    }
    IterFun(listdata);
    listdata.pop_back();
    //listdata.clear();
    IterFun(listdata);
    listdata.insert(listdata.begin(),99);
    IterFun(listdata);
    return 0;
}