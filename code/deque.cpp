/**
 * @author [chenjunlong]
 * @version [v1.0, 2023-03-21]
 * @see [STL]
 * @container deque 
 * @since [v1]
 * @deprecated 双端队列
*/
#include <iostream>
#include <deque>
using namespace std;

#define NUM 15
/*
* 遍历容器并打印元素
*/
void fun(deque<int> d)
{
    cout<<endl;
    if(!d.empty())//如果容器中 无元素，为空
    {    for(int i=0;i<NUM;i++)
        {
        cout <<d[i]<<" ";
        }
    }
    else{
        cout << "元素为空！" << endl;
    }
    cout <<"当前容器大小："<< d.size()<<endl;
}
int main() {
    cout << "deque 双端队列!"<<endl;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    //创建
    deque<int> deq(10,5);//初始化10个元素值为5的队列容器
    deque<int> deq1(10);//初始化10个元素默认值为0 的队列容器
    deque<int> deq2(deq1);//拷贝deq1 进行构造
    deque<int> deq3(arr,arr+9);//通过数组进行构造
    
    fun(deq);
    fun(deq1);
    fun(deq2);
    fun(deq3);
    
    auto it = deq.begin();
    auto iter = deq.cbegin();
    *it = 6;
    //*iter = 11   错误，因为cbegin()返回的是一个const迭代器
    *(it+1) = 7;
    cout << "采用迭代器改变元素值" << endl;
    fun(deq);
    cout << "从尾部添加元素" << endl;
    deq.push_back(33);//从尾部添加元素
    fun(deq);
    cout << "从头部添加元素" << endl;
    deq.push_front(66);//从头部添加元素
    fun(deq);
    deque<int>::iterator itd = deq.begin();
    itd = deq.insert(itd+1,99);//在第二个元素前插入元素99
    fun(deq);
    itd = deq.erase(deq.begin());//rease 删除指定元素
    fun(deq);
    cout <<"itd指向的元素是：" <<*itd<<endl;
    cout <<"itd+1指向的元素是：" <<*(itd+1)<<endl;
    deq.clear();
    fun(deq);
    cout <<"itd指向的元素是：" <<*itd<<endl;
    cout <<"itd+1指向的元素是：" <<*(itd+1)<<endl;//这时的迭代器已经失效
    return 0;
}
/**
运行结果：
        deque 双端队列!
        
        5 5 5 5 5 5 5 5 5 5 0 0 0 0 0 当前容器大小：10
        
        0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 当前容器大小：10
        
        0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 当前容器大小：10
        
        1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 当前容器大小：9
        采用迭代器改变元素值
        
        6 7 5 5 5 5 5 5 5 5 0 0 0 0 0 当前容器大小：10
        从尾部添加元素
        
        6 7 5 5 5 5 5 5 5 5 33 0 0 0 0 当前容器大小：11
        从头部添加元素
        
        66 6 7 5 5 5 5 5 5 5 5 33 0 0 0 当前容器大小：12
        
        66 99 6 7 5 5 5 5 5 5 5 5 33 0 0 当前容器大小：13
        
        99 6 7 5 5 5 5 5 5 5 5 33 33 0 0 当前容器大小：12
        itd指向的元素是：99
        itd+1指向的元素是：6
        
        元素为空！
        当前容器大小：0
        itd指向的元素是：99
        itd+1指向的元素是：543644472
*/