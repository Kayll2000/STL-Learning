/**
* @author [chenjunlong]
* @version [v1.0, 2023-02-28]
* @see [STL]
* @container map
* @since [v1]
* @deprecated 关联式容器,map底层是红黑树
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

/**
 * 正向迭代器遍历容器 API
 */
void IterFun(map<int,string> ver)
{
    if(!ver.empty())//empty() 若map为空返回TRUE
    {
        cout<<endl;
        cout<<"map of size: "<<ver.size()<<endl;//返回map中的元素数
        cout<<"map of maxsiez  "<<ver.max_size()<<endl;//map 的最大容量
        for(auto it = ver.begin();it != ver.end();it++)
        {
            cout<<"Key:"<<it->first<<" Value:"<<it->second<<endl;
        }
        cout<<endl;
    }else{
        cout<<"map is empty!"<<endl;
    }
}

int main()
{
    int n;
    map<int,string> Stu;
    map<int,string> Mast;
    map<int,string>Bat{ {1,"data1"},{2,"data2"},{3,"data3"} };

    Stu.insert(pair<int,string>(0,"Stu1"));//插入pair数据
    Stu.insert(map<int,string>::value_type(1,"Stu2"));//插入value_type数据
    
    Stu[2] = "Stu3";//通过“array”的方式赋值
    Stu[3] = "Stu4";
    
    map<int,string> Tech(Stu);//构造
    Mast = Stu;//赋值
    
    
    map<int,string>::iterator it,itstart,itend;
    itstart = Stu.begin();
    itend = Stu.end();
    for(it = itstart;it!=itend;it++)//采用迭代器遍历
    {
        cout<<"Key:"<<it->first<<" Value:"<<it->second<<endl;
    }
    IterFun(Tech);
    
    cout<<Stu[0]<<endl;
    cout<<Stu[1]<<endl;
    
    auto iter = Stu.find(1);
    auto iter2 = Stu.find(100);
    //find() 找到访问数据所在对象的位置，找不到返回和end函数值一样
    if(iter != Stu.end())
    {
        cout<<"find! "<<iter->first<<" "<<iter->second<<endl;   
    }else
    {
        cout<<"no found!"<<endl;
    }
    iter2!=Stu.end()?(cout<<"find! "<<iter2->first<<" "<<iter2->second<<endl):(cout<<"no found!"<<endl);
    
    Stu.erase(iter);//用迭代器删除，删除了Stu[1]即Stu2
    IterFun(Stu);
    
    n = Stu.erase(0);//删除成功返回1，否则返回0
    if(n)
    {
        cout<<"删除成功！ "<<n<<endl;
    }else
    {
        cout<<"删除失败！"<<endl;
    }
    IterFun(Stu);
    
    Stu.erase(Stu.begin(),Stu.end());
    IterFun(Stu);
    IterFun(Tech);
    Tech.clear();
    IterFun(Tech);
    IterFun(Mast);
    
    map<int,string>::reverse_iterator reit;//反向迭代器
    for(reit=Mast.rbegin();reit!=Mast.rend();reit++)
    {
        cout<<"Key:"<<reit->first<<" Value:"<<reit->second<<endl;
    }
    IterFun(Bat);
    Mast.swap(Bat);//将Mast的数据和Bat进行互换
    IterFun(Bat);
    IterFun(Mast);
    cout<<"Bat 1 count "<<Bat.count(1)<<endl;
    /*
    map<key,value>举例，find()方法返回值是一个迭代器，成功返回迭代器指向要查找的元素，失败返回的迭代器指向end。
    count()方法返回值是一个整数，1表示有这个元素，0表示没有这个元素
    */
    
    return 0;
}