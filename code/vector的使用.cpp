#include<iostream>
#include<vector>
#include<algorithm>//reverse 和sort 的头文件
using namespace std;
//using std::vector;

bool Comp(const int &a,const int &b)//重写比较函数，为了sort能够降序排序
{
    return a>b;
}

int main()
{
    int i = 0;
    int j = 0;
    vector<int> Demo;//建立一个向量
    vector<int> Demo_1(10,5);//初始化了10个值为5的元素
    //vector<int> Demo_2(Demo);//这里拷贝的话，由于Demo还没有初始化值，所以拷贝了个空
    Demo.push_back(1);//推入元素，数组【0】是 1
    Demo.push_back(2);
    vector<int> Demo_2(Demo);
    vector<int> Demo_3(10);//初始化了10个默认值为0的元素
    cout<<"Demo_2[1] is "<<Demo_2[0]<<endl;
    
    cout<<"Demo[0] is "<<Demo[0];//用数组下标访问
    cout<<"\n";
    vector<int>::iterator it;//用迭代器访问
    
    for(it=Demo.begin();it!=Demo.end();it++)
        cout<<"Demo["<<i++ <<"] = "<<*it<<endl;
        cout<<endl;
    for(it=Demo_1.begin();it!=Demo_1.end();it++)
        cout<<"Demo_1["<<j++ <<"] = "<<*it<<endl;
    cout<<endl;
    j = 0;
    for(it=Demo_3.begin();it!=Demo_3.end();it++)
        cout<<"Demo_3["<<j++ <<"] = "<<*it<<endl;
    cout<<"Demo_3 of size:"<<Demo_3.size()<<endl;       
    Demo_3.insert(Demo_3.begin()+1,1); //在第1个元素前面插入1;
    cout<<endl;
    cout<<"after insert"<<endl;
    cout<<"Demo_3 of size:"<<Demo_3.size()<<endl;
    j = 0;
    
    for(it=Demo_3.begin();it!=Demo_3.end();it++)
        cout<<"Demo_3["<<j++ <<"] = "<<*it<<endl;
        cout<<endl;
    cout<<"after erase"<<endl;
    cout<<"Demo_3 of size:"<<Demo_3.size()<<endl;
    Demo_3.erase(Demo_3.begin()+2); //删除第3个元素
    
    j = 0;
    for(it=Demo_3.begin();it!=Demo_3.end();it++)
    cout<<"Demo_3["<<j++ <<"] = "<<*it<<endl;
    cout<<endl;
    
    j = 0;
    cout<<"after reverse"<<endl;
    reverse(Demo_3.begin(),Demo_3.end());//将元素翻转
        for(it=Demo_3.begin();it!=Demo_3.end();it++)
    cout<<"Demo_3["<<j++ <<"] = "<<*it<<endl;
    
    j = 0;
    cout<<endl;
    cout<<"after sort"<<endl;
    sort(Demo_3.begin(),Demo_3.end());//sort 默认（升序）从小到大排序
        for(it=Demo_3.begin();it!=Demo_3.end();it++)
    cout<<"Demo_3["<<j++ <<"] = "<<*it<<endl;
    
    j = 0;
    cout<<endl;
    cout<<"after sort hight -> low"<<endl;
    sort(Demo_3.begin(),Demo_3.end(),Comp);
        for(it=Demo_3.begin();it!=Demo_3.end();it++)
    cout<<"Demo_3["<<j++ <<"] = "<<*it<<endl;    
    
    
    Demo_3.clear();//vector.clear()的真正作用是：把size设置成0，capacity（能力）不变
    cout<<"Demo_3 of size:"<<Demo_3.size()<<endl;
        return 0;
}