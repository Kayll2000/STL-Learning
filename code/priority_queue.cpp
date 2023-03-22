/**
 * @author [chenjunlong]
 * @version [v1.0, 2023-03-22]
 * @see [STL]
 * @container priority_queue
 * @since [v1]
 * @deprecated 优先队列 ·本质上是用堆实现 ·具有队列的所有特性 ·不能使用list进行初始化操作
*/

#include <iostream>
#include <queue>
//#include <vector>
using namespace std;
#define NUM 10

int main() {

priority_queue<int> pq1;//默认 大顶堆
priority_queue<int,vector<int>,less<int>> pq2;//大顶堆
priority_queue<int,vector<int>,greater<int>> pq3;//小顶堆

for(int i = 0;i < NUM;i++)
{
    pq1.push(i);
    pq2.push(i);
    pq3.push(i);
}
//pq1.emplace(99);  //原地构造一个元素并插入队列
cout <<"pq1 size:"<<pq1.size() << endl;
cout <<"pq2 size:"<<pq2.size() << endl;
cout <<"pq3 size:"<<pq3.size() << endl;
cout << "开始遍历" << endl;
//for(int j = 0;k < NUM ;j++)
while(!pq1.empty() || !pq2.empty() || !pq3.empty())
{
    cout <<"pq1:"<<pq1.top() << endl;
    cout <<"pq2:"<<pq2.top() << endl;
    cout <<"pq3:"<<pq3.top() << endl;
    pq1.pop();
    pq2.pop();
    pq3.pop();
}

    return 0;
}
/*
编译运行结果：
            pq1 size:10
            pq2 size:10
            pq3 size:10
            开始遍历
            pq1:9
            pq2:9
            pq3:0
            pq1:8
            pq2:8
            pq3:1
            pq1:7
            pq2:7
            pq3:2
            pq1:6
            pq2:6
            pq3:3
            pq1:5
            pq2:5
            pq3:4
            pq1:4
            pq2:4
            pq3:5
            pq1:3
            pq2:3
            pq3:6
            pq1:2
            pq2:2
            pq3:7
            pq1:1
            pq2:1
            pq3:8
            pq1:0
            pq2:0
            pq3:9
*/