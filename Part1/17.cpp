#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int x;
    do{
        cin >> x;
        v.push_back(x);
    }while(cin.get()!='\n');
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int> s;
    do{
        cin >> x;
        s.push_back(x);
    }while(cin.get() != '\n');
    for(int i=0; i<s.size(); i++){
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}