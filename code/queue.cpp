/**
 * @author [chenjunlong]
 * @version [v1.0, 2023-03-22]
 * @see [STL]
 * @container queue
 * @since [v1]
 * @deprecated 队列 跟stack一样不能使用迭代器，不能用vector初始化
*/
#include <iostream>
#include <queue>
using namespace std;

void IsEmpty(queue<int> _qu)
{
    if(!_qu.empty())
    {
        cout << "队列非空！" << endl;
    }else{
        cout << "队列已空！" << endl;
    }
}

int main() {

    deque<int> de(10,66);
    queue<int> qu(de);
    queue<int> qubat;
    int tmp,qu_size;
    qu_size = qu.size();
    //error
    //auto it =qu.begin(); queue没有迭代器
    //for(it;it != qu.end();it++)
      //  cout << *it << " ";
    //遍历前 qu 和 qubat 的大小
    cout<<"qu.size is " << qu.size() << endl;
    cout<<"qubat.size is " << qubat.size() << endl;
    IsEmpty(qu);
    IsEmpty(qubat);
    for(int i=0;i < qu_size;i++)
    {
        cout <<"queue 的大小："<< qu.size() << endl;
        tmp = qu.front();
        cout <<tmp<<endl;
        qubat.push(tmp);
        qu.pop();
        //cout << "i:"<<i<<endl;
    }
    cout<<"qu.size is " << qu.size() << endl;
    cout<<"qubat.size is " << qubat.size() << endl;
    IsEmpty(qu);
    IsEmpty(qubat);

    cout << "交换后：" << endl;
    swap(qu,qubat);
    IsEmpty(qu);
    IsEmpty(qubat);
    cout<<"qu.size is " << qu.size() << endl;
    cout<<"qubat.size is " << qubat.size() << endl;

    return 0;
}

/*
编译运行结果(PC端 )：
        qu.size is 10
        qubat.size is 0
        队列非空！
        队列已空！
        queue 的大小：10
        66
        queue 的大小：9
        66
        queue 的大小：8
        66
        queue 的大小：7
        66
        queue 的大小：6
        66
        queue 的大小：5
        66
        queue 的大小：4
        66
        queue 的大小：3
        66
        queue 的大小：2
        66
        queue 的大小：1
        66
        qu.size is 0
        qubat.size is 10
        队列已空！
        队列非空！
        交换后：
        队列非空！
        队列已空！
        qu.size is 10
        qubat.size is 0
*/