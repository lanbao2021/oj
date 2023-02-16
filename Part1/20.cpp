#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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

    int n;
    cin >> n;

    int count=0;
    for(int i=0; i+1<data.size(); i++){
        if(data[i] == 1)
            continue;

        if(i==0 && data[1]==0){
            data[i] = 1;
            count++;
            continue;
        }
        
        if(data[i-1]==1 || data[i+1]==1)
            continue;

        if(data[i-1]!=1 && data[i+1]!=1){
            data[i] = 1;
            count++;
            continue;
        }

    }
    if(count>=n){
        cout << "true";
        return 0;
    }
    cout << "false";
    return 0;
}