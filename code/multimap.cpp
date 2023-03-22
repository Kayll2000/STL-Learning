/**
* @author [chenjunlong]
* @version [v1.0, 2023-03-22]
* @see [STL]
* @container multimap
* @since [v1]
* @deprecated 关联式容器，按特定的次序（根据key）存储由键和值组合而成的元素。
              多个键值对之间的key可以重复和map的唯一区别是multimap中的key可以重复，而map的key是唯一的。
*/

#include <iostream>
#include <map>

using namespace std;
/**
 * @函数模板
 * @function：传入一个multimap类型容器后进行遍历并打印其键值对个数
*/
template <class T>
void PFun(T mmap)
{
    cout << endl;
    if(!mmap.empty()){
        auto it = mmap.begin();
        for(it;it != mmap.end();it++)
        {
            cout<<it->first<<" "<<it -> second << endl;
        }
    }else{
         cout << "mmap is empty!"<<endl;
    }
    cout <<"该容器键值对个数为："<< mmap.size() <<endl;
}

int main()
{
    multimap<string,string> mmap1;//构造一个空的容器
    multimap<string,string> mmap2{//构造容器并初始化
        {"STU1","C"},
        {"STU2","Python"},
        {"STU3","C++"},
        {"STU3","C#"}//multimap和map的唯一区别是multimap中的key可以重复，而map的key是唯一的。
    };
    multimap<string,string> mmap3(mmap2);//拷贝构造
    cout << "mmap2:" << endl;
    PFun(mmap2);
    cout << "mmap3:" << endl;
    PFun(mmap3);
    
    mmap3.insert(pair<string,string>("STU4","C#"));//插入pair键值
    cout << "mmap3:" << endl;
    PFun(mmap3);
    
    mmap3.swap(mmap2);//交换mmap3 和 mmap2 两个容器的元素
    //操作的 2 个键值对的类型必须相同
    cout << "mmap3:" << endl;
    PFun(mmap3);
    cout << "mmap2:" << endl;
    PFun (mmap2);
    
    mmap3.erase("STU1");
    cout << "mmap3:" << endl;
    PFun(mmap3);
    
    mmap3.clear();//清空容器
    cout << "mmap3:" << endl;
    PFun(mmap3);
    
    mmap2.erase("STU3");//删除key为 STU3的元素
    cout << "mmap2:" << endl;
    PFun(mmap2);
    
    return 0;
}

/*
编译运行结果：
            mmap2:
            
            STU1 C
            STU2 Python
            STU3 C++
            STU3 C#
            该容器键值对个数为：4
            mmap3:
            
            STU1 C
            STU2 Python
            STU3 C++
            STU3 C#
            该容器键值对个数为：4
            mmap3:
            
            STU1 C
            STU2 Python
            STU3 C++
            STU3 C#
            STU4 C#
            该容器键值对个数为：5
            mmap3:
            
            STU1 C
            STU2 Python
            STU3 C++
            STU3 C#
            该容器键值对个数为：4
            mmap2:
            
            STU1 C
            STU2 Python
            STU3 C++
            STU3 C#
            STU4 C#
            该容器键值对个数为：5
            mmap3:
            
            STU2 Python
            STU3 C++
            STU3 C#
            该容器键值对个数为：3
            mmap3:
            
            mmap is empty!
            该容器键值对个数为：0
            mmap2:
            
            STU1 C
            STU2 Python
            STU4 C#
            该容器键值对个数为：3
*/