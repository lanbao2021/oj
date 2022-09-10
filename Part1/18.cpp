#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='6'){
            str[i]='9';
            break;
        }
    }
    cout << str;
    return 0;
}