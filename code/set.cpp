/**
* @author [chenjunlong]
* @version [v1.0, 2023-03-01]
* @see [STL]
* container set
* @since [v1]
* @deprecated 关联式容器,set底层是红黑树
*/

#include <iostream>
#include <set>
using namespace std;

/**
 * 正向迭代器遍历容器 API
 */
void IterFun(set<int> ver)//用函数重载
{
    if(!ver.empty()){
        cout<<"set is exit"<<endl;
        for(auto it = ver.begin();it!=ver.end();it++)
        {
            cout<<*it<<endl;
        }
    }else{
        cout<<"set is empty!"<<endl;
    }
}
/**
 * 正向迭代器遍历容器 API，函数重载
 */
void IterFun(set<string> ver)
{
if(!ver.empty()){
    cout<<"set is exit"<<endl;
    for(auto it = ver.begin();it!=ver.end();it++)
    {
        cout<<*it<<endl;
    }
}else{
        cout<<"set is empty!"<<endl;
     }
}
int main() {
    
    set<int> data;
    data.insert(1);
    data.insert(2);
    set<int> databat(data);
    set<string> strdata{"http://Web/java","http://Web/C++","http://Web/python"};
    set<int>::iterator datait;
    
    IterFun(data);
    IterFun(strdata);
    IterFun(databat);
    
    cout<<"data size: "<<data.size()<<endl;
    cout<<"strdata: "<<strdata.size()<<endl;
    cout<<"data max szie: "<<data.max_size()<<endl;
    data.clear();
    IterFun(data);
    databat.erase(1);
    IterFun(databat);
    cout<<"databat count  " <<databat.count(2)<<endl;//由于 set 容器中各元素的值是唯一的，因此该函数的返回值最大为 1。
    auto itfind = databat.find(2);
    if(itfind != databat.end())
    {
        cout<<"find!"<<endl;
    }else
    {
        cout<<"no find !"<<endl;
    }
    cout<<"find "<<*itfind<<endl;
    return 0;
}