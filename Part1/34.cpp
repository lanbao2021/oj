#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

int ans=0;

set<string> differ;

void dfs(int target, vector<int> &coins, string str){
    if(target<0){
        return;
    }
    if(target==0){
        // ans++;
        // for(int i=0; i<str.size(); i++){
        //     cout << str[i] << " ";
        // }
        // cout << endl;
        
        sort(str.begin(), str.end());
        differ.insert(str);
        return;
    }
    
    for(int i=0; i<coins.size(); i++){
        // choose it
        target -= coins[i];
        str.push_back(coins[i]+'0');
        dfs(target, coins, str);
        // drop and choose next
        target += coins[i];
        str.pop_back();
    }
}

void get_one_line(vector<int> &tmp){
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        tmp.push_back(stoi(s));
    }
}

int main(){
    int target;
    vector<int> target_tmp;
    get_one_line(target_tmp);
    target = target_tmp.back();

    vector<int> coins;
    get_one_line(coins);

    string tmp;
    // cout << "=================" << endl;
    dfs(target, coins, tmp);
    // cout << "=================" << endl;
    // cout << ans << endl;
    // cout << "=================" << endl;
    cout << differ.size() << endl;

    return 0;
}