#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    int x;
    do{
        cin >> x;
        v.push_back(x);
    }while(cin.get() != '\n');

    vector<int> s;
    do{
        cin >> x;
        s.push_back(x);
    }while(cin.get() != '\n');

    sort(v.begin(), v.end());
    sort(s.begin(), s.end());

    int n=0, i=0, j=0;
    while(i<v.size() && j<s.size()){
        if(v[i] <= s[j]){
            n++;
            i++;
            j++;
            continue;
        }
        if(v[i]>s[j]){
            j++;
            continue;
        }
    }
    cout << n << endl;
    return 0;
}