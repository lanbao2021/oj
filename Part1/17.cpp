#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> g, s;
    int value;

    while(cin >> value){
        g.push_back(value);
    }

    while(cin >> value){
        s.push_back(value);
    }

    for(int i=0; i<g.size(); i++)
        cout << g[i] << " ";
    cout << endl;
    
    return 0;
}