#include<iostream>
#include<sstream>        //istringstream 必须包含这个头文件
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    vector<int> data;

    //键入ctrl+Z，才能跳出循环
    while(getline(cin,str)){
        //构造一个istringstream对象is
        istringstream is(str);
        string s;
        //类似cin，这里可以is流中读取字符串，遇到空格，表示读取一个字符完成
        //读到结尾后,会设置标志位，然后会利用其成员函数operator bool实现类型转换，跳出循环
        while(is>>s)
        {
            data.push_back(stoi(s));
        }
    }

    cout<<"data of input is : "<<endl;
    for(auto& i:data)
        cout<< i<<' ';

    system("pause");
    return 0;
} 

