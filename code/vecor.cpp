/**
* @author [chenjunlong]
* @version [v1.0, 2023-02-28]
* @see [STL]
* @container vector
* @since [v1]
* @deprecated 向量，底层是动态数组
*/
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>   
using namespace std;

#define SUM 10
#define DELETEALL FALSE

/**
 * 正向迭代器遍历容器 API
 */
void IteratorFun(vector<int> v1)
{
    vector<int>::iterator itstart,itend,it;
    itstart = v1.begin();
    itend = v1.end();
    if(v1.empty())//判断是否为空
    {
        cout<<"empty!!"<<endl;
    }else{
        cout<<"正在使用正向迭代器···"<<endl;
        cout<<"开始遍历···"<<endl;
        for(it = itstart;it != itend;it++)
        {
            cout<<*it<<endl;
        }
    }
}
void VerFun(vector<int> v1)
{
    cout<<"ver size is :"<<v1.size()<<endl;//正常
    cout<<"ver capacity is "<<v1.capacity()<<endl;//BUG 好像传进来后，容量变了
}

int main() {
    int value = 10;
    vector<int> v1;//默认初始化为0
    vector<string> vs1;//默认初始化为空字符串
    vector<vector<int> > v2;//相当于二维数组inta[n][n]
    vector<int> v3 = {1,2,3,4,5};//列表初始化
    vector<string> vs2 = {"hi","my","name","is","chen"};
    vector<int> v4(5,1);//初始化为 1 ，1， 1， 1， 1  即初始化5个值为1的元素
    vector<int> v5(10);//初始化10个值为0的元素
    
    for(int i = 0 ;i<SUM;i++)
    {
        v1.push_back(i);//添加元素
    }
    
    //访问
    //数组形式访问
    cout<<"使用数组形式访问"<<endl;
    for(int j = 0;j<SUM;j++)
    {
        cout<<v1[j]<<endl;
    }
    //迭代器形式访问
    //正向迭代器
    vector<int>::iterator itstart,itend,it;
    itstart = v1.begin();
    itend = v1.end();
    cout<<"使用正向迭代器"<<endl;
    for(it = itstart;it != itend;it++)
    {
        cout<<*it<<endl;
    }
    //反向迭代器
    cout<<"使用反向迭代器"<<endl;
    for(vector<int>::reverse_iterator iter = v1.rbegin();iter != v1.rend();iter++)
    {
        cout<<*iter<<endl;
    }
    
    v1.insert(v1.begin()+1,99);//在v1.begin()+1位置前插入一个99元素
    IteratorFun(v1);
    cout<<"第一次执行insert "<<endl;
    v1.insert(v1.begin()+2,3,88);//在第3个位置前插入3个88元素
    IteratorFun(v1);
    cout<<"第二次执行insert "<<endl;
    array<int,3> arr{77,77,77};//在第4个位置前插入其他容器{不限于vector}，从begin到end中的元素
    v1.insert(v1.begin()+3,arr.begin(),arr.end());
    IteratorFun(v1);
    cout<<"第三次执行insert "<<endl;
    v1.insert(v1.end(),{66,66,66});//在最后元素前插入一个初始化列表的所有元素
    IteratorFun(v1);
    VerFun(v1);
    cout<<"第一次删除前SIZE "<<v1.size()<<endl;
    cout<<"第一次删除前Capacity "<<v1.capacity()<<endl;
    v1.pop_back();//删除最后一个元素，size - 1 ，capacity不变
    IteratorFun(v1);
    VerFun(v1);
    cout<<"第一次删除后SIZE "<<v1.size()<<endl;
    cout<<"第一次删除后Capacity "<<v1.capacity()<<endl;
    IteratorFun(v1);
    cout<<"即将删除的元素："<<v1[1]<<endl;
    auto itdelete = v1.erase(v1.begin()+1);//删除第2个元素，返回被删除元素下一个位置的迭代器
    IteratorFun(v1);
    cout<<"返回的迭代器："<<*itdelete<<endl;
    cout<<"第二次删除后SIZE "<<v1.size()<<endl;
    cout<<"第二次删除后Capacity "<<v1.capacity()<<endl;
    
    //第三种删除是被删除的元素位置与最后一个元素位置交换后，执行pop_back
    cout<<"交换前begin "<<v1[0]<<endl;
    cout<<"交换前end "<<v1[18]<<endl;
    swap(v1[0],v1[18]);
    //IteratorFun(v1);  //有bug，交换后第一个元素值变了，但最后一个元素值扔不变
    cout<<"交换后begin "<<v1[0]<<endl;
    cout<<"交换后end "<<v1[18]<<endl;
    v1.pop_back();
    cout<<"end is "<<v1[17]<<endl;
    cout<<"第三次删除后SIZE "<<v1.size()<<endl;
    cout<<"第三次删除后Capacity "<<v1.capacity()<<endl;
    IteratorFun(v1);
    
    #if DELETEALL
    v1.erase(v1.begin(),v1.end());//删除begin到end区域的元素
    cout<<"第四次删除后SIZE "<<v1.size()<<endl;
    cout<<"第四次删除后Capacity "<<v1.capacity()<<endl;
    IteratorFun(v1);
    #endif
    cout<<"use remove "<<endl;
    auto ret = remove(v1.begin(),v1.end(),77);//删除vector中所有值为77的元素，使用remove不会改变size和capacity
    //remove只是将待删除的元素移动到vector的前端，并不是真正的删除
    cout<<"remove后返回的迭代器 "<<*ret<<endl;
    cout<<"第五次删除后SIZE "<<v1.size()<<endl;
    cout<<"第五次删除后Capacity "<<v1.capacity()<<endl;
    IteratorFun(v1);
    
    #if DELETEALL
    //删除容器中所有元素
    v1.clear();
    cout<<"第五次删除后SIZE "<<v1.size()<<endl;
    cout<<"第五次删除后Capacity "<<v1.capacity()<<endl;
    IteratorFun(v1);
    #endif
    //清空容量capacity
    vector<int>().swap(v1);
    cout<<"释放后SIZE "<<v1.size()<<endl;
    cout<<"释放后Capacity "<<v1.capacity()<<endl;
    
    vector<int*> p;
    p.push_back(&value);
    cout<<"p【value address】 is "<<p[0]<<endl;//p[0存放value的地址]
    cout<<"value is "<<*p[0]<<endl;
    cout<<"p size is "<<p.size()<<endl;
    p.clear();
    vector<int*>().swap(p);
    cout<<"p size is "<<p.size()<<endl;
    
    return 0;
}