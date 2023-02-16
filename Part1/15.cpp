#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    
    string SHORT, LONG;
    if(s1.size() > s2.size()){
        LONG = s1;
        SHORT = s2;
    }
    else{
        LONG = s2;
        SHORT = s1;
    }

    int num=0;
    for(int i=0; i < SHORT.size(); i++)
        for(int j=0; j < LONG.size(); j++){
            if(SHORT[i] == LONG[j]){
                num++;
                break;
            }
        }
    cout << num << endl;
    return 0;
}