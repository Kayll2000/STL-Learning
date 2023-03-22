/**
* @author [chenjunlong]
* @version [v1.0, 2023-03-22]
* @see [STL]
* @container multiset
* @since [v1]
* @deprecated 关联式容器,排序好的集合，multiset支持重复，而set会去重。
*/
#include <iostream>
#include <set>

using namespace std;

template <class T>
void PFun(T _set)
{
    cout << endl;
    if(!_set.empty()){
        cout << "set is Non-empty!" << endl;
        auto it = _set.begin();
        for(it;it != _set.end();it++)
        {
            cout <<*it <<" ";
        }
    }else{
        cout << "set is empty!" << endl;
    }
}
/*
??迭代器只读，不能通过迭代器赋值？？
template <class T>
void SFun(T it,int num)
{
    cout <<"test"<<num<<endl;
    for(int i=0;i<num;i++)
    {
        // _set.insert(i);
        *it = i;
        it++;
        cout<<i<<endl;//debug
    }
}
*/
template <class T>
int Find(T _set,int tmp)
{
    cout << endl;
    cout <<"set's size is " << _set.size()<<endl;
    if(_set.find(tmp) != _set.end())//find 如果找到了返回第一个找到的元素的迭代器，找不到返回尾部迭代器
    {
        cout << tmp <<" find!" <<"\t出现的次数为："<<_set.count(tmp)<< endl;
    
        return true;
    }
    else{
        cout << tmp << " non find"<< endl;
        return false;
    }
}
int main()
{
    bool flag = false;
    multiset<int> set1;// 默认构造，升序
    multiset<int,less<int>> set2;//升序
    multiset<int,greater<int>> set3;//降序
    
    for(int i=0;i<10;i++)
    {
        set1.insert(i);
        set3.insert(i);
    }
    // auto it1 = set1.begin();
    // auto it3 = set3.begin();
    // SFun(it1,10);
    // SFun(it3,10);
    auto it = set1.begin();
    for(it;it != set1.end();it++)
    {
        cout << *it << " ";
    }
    PFun(set3);
    cout <<"\nflag -> " << flag <<endl;
    flag = Find(set3,1);
    cout <<"flag -> " << flag <<endl;
    Find(set3,19);
    set3.erase(8);
    
    return 0;
}

/*
运行结果：
        0 1 2 3 4 5 6 7 8 9 
        set is Non-empty!
        9 8 7 6 5 4 3 2 1 0 
        flag -> 0
        
        set's size is 10
        1 find!	出现的次数为：1
        flag -> 1
        
        set's size is 10
        19 non find

*/