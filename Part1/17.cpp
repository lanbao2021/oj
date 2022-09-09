#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> g, s;
    char ch;
    while((ch = cin.get()) != '\n'){
        g.push_back(ch - '0');
    }

    for(int i=0; i<g.size(); i++){
        cout << g[i] << " ";
    }
    cout << endl;
    
    return 0;
}