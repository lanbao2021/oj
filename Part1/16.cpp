#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int frequency[100] = {0};
    for(int i=0; i<s.size(); i++){
        frequency[s[i] - 'A']++;
    }
    int odd=0, even=0, single=0;
    int ans=0;
    for(int i=0; i<100; i++){
        if(frequency[i]==1){
            single++;
            continue;
        }
        if(frequency[i] % 2 == 1){
            ans += (frequency[i]-1);
            single++;
            continue;
        }
        if(frequency[i] % 2 == 0){
            ans += frequency[i];
            continue;
        }
    }
    if(single)
        ans++;
    cout << ans << endl;
    return 0;
}