/**
 * @author [chenjunlong]
 * @version [v1.0, 2023-03-21]
 * @see [STL]
 * @container stack 
 * @since [v1]
 * @deprecated 栈,LIFO( 后进先出)在STL中stack中只能通过top()来访问栈顶元素
*/

#include <iostream>
#include <stack>

using namespace std;
#define NUM 10

void fun(stack<int> st)
{
    if(!st.empty()){
    cout << "stack of size is " << st.size() << endl;        
    }else{
        cout << "stack is empty!" << endl;
    }
}
int main()
{
    stack<int> st;
    stack<int> stbat;   //对st的备份
    int bat;
    for(int i=0;i<NUM;i++)
    {
        st.push(i);
    }
    cout << "top elem " << st.top() << endl;//栈顶元素
    //只能通过st.top访问
    for(int j=0;j<NUM;j++)//遍历stack
    {
        bat = st.top();
        cout <<bat<<endl;;
        st.pop();
    
        fun(st);
        stbat.push(bat);
    }
    fun(stbat);

    return 0;
}
/** 运行结果：
             top em 9
            9
            stack of size is 9
            8
            stack of size is 8
            7
            stack of size is 7
            6
            stack of size is 6
            5
            stack of size is 5
            4
            stack of size is 4
            3
            stack of size is 3
            2
            stack of size is 2
            1
            stack of size is 1
            0
            stack is empty!
            stack of size is 10
*/