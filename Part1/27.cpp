#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int target;
int ans=0;

void dfs(int val, int idx, vector<int>& num){
    if(idx==num.size()){
        if(val==target){
            ans++;
            return;
        }
        return;
    }
    dfs(val+num[idx], idx+1, num);
    dfs(val-num[idx], idx+1, num);
}

int main(){
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        data.push_back(stoi(s));
    }

    cin >> target;

    dfs(0, 0, data);
    
    cout << ans << endl;

    return 0;
}