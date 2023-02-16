#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        data.push_back(stoi(s));
    }
    sort(data.begin(), data.end(), greater<int>());
    // for(int i=0; i<data.size(); i++){
    //     cout << data[i] << " ";
    // }
    // cout << endl;
    int a, b, c;
    for(int i=0; i+2<data.size(); i++){
        a = data[i];
        b = data[i+1];
        c = data[i+2];
        if(a < b+c){
            cout << a+b+c;
            return 0;
        }
    }
    cout << 0;
    return 0;
}