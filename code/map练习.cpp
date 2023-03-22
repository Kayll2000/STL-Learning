#include <iostream>
#include <map>
using namespace std;
#define MAX(x,y) (x>y)?(x):(y)

int main() {
    int value;
    int other_value;
    int max;
    cout << "test!"<<endl;
    cout <<endl; 
    // cin>>value>>other_value;
    
    // cout<<"value = " << value<<endl;
    // cout << "other value = "<<other_value<<endl;
    // max = MAX(value,other_value);
    // cout<<"the MAX = "<<max<<endl;
    //map ——> 键值对容器
    
    map < int, int > m1, m2, m3;
    map < int, int >::iterator m1_Iter;
    m1.insert ( pair < int, int >  ( 1, 10 ) );
    m1.insert ( pair < int, int >  ( 2, 20 ) );
    m1.insert ( pair < int, int >  ( 3, 30 ) );
    
    m2.insert ( pair < int, int >  ( 10, 100 ) );
    m2.insert ( pair < int, int >  ( 20, 200 ) );
    
    m3.insert ( pair < int, int >  ( 30, 300 ) );
    for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
    cout << " " << m1_Iter->second;
    cout   << "." << endl;
    //swap()交换是两个容器的交换
   m1.swap( m2 );
   cout << "After swapping with m2, map m1 is:"<<endl;
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
      cout  << "." << endl;
    
    map<int,string> mapPerson;//构造
    map<int,int> mapPerson_ot;
    mapPerson.insert(pair <int,string>(1,"Tom"));
    mapPerson.insert(pair <int,string>(2,"Kayll"));
    mapPerson.insert(pair <int,string>(3,"Lee"));
    mapPerson.insert(pair <int,string>(4,"Marry"));
    mapPerson_ot.insert(pair <int,int>(1,10));
    
    map < int ,string> ::iterator it;//前向迭代器
    map <int , string> ::iterator itEnd;
    it = mapPerson.begin();//返回指向 map 头部的迭代器
    itEnd = mapPerson.end();//返回指向 map 末尾的迭代器


    it = mapPerson.find(1);//寻找键值为1的元素
   if(it == mapPerson.end())
        cout<<"we do not find "<<endl;
   else cout<<"we find "<<endl;
   
   //size_type erase(const Key&key);	//通过关键字删除
   mapPerson.erase(2);//删除键值为2 ——> Kayll
//mapPerson.clear();//清除所有元素
   while (it != itEnd) {   //使用迭代器去遍历
   cout<<it->first<<' '<<it->second<<endl;  
   it++;
}

map < int, string > ::reverse_iterator iter;//反向迭代器
for(iter = mapPerson.rbegin(); iter != mapPerson.rend(); iter++) 
	cout<<iter->first<<"  "<<iter->second<<endl;
cout<<"this is " << mapPerson[1]<<endl;//通过数组形式去访问map中元素
cout<<"this is " << it->first<<endl;
cout<<"this is " << mapPerson.count(3)<<endl;//count 返回元素出现的个数
cout<<"this is " << mapPerson.size()<<endl;//返回map中元素个数
cout<< "非空为：" << mapPerson.empty();  //若map中元素为空，则返回TRUE

    return 0;
}