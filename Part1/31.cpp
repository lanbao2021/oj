#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

vector<int> single_price;
int special_num;
vector<int> special_price;
vector<vector<int>> special_item_num;
vector<int> needs;

vector<int> ans;

void get_special(){
    vector<int> tmp;
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        tmp.push_back(stoi(s));
    }
    special_price.push_back(tmp.back());
    tmp.pop_back();
    special_item_num.push_back(tmp);
}

void get_needs(){
    vector<int> tmp;
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        needs.push_back(stoi(s));
    }
}

bool judge(vector<int> &tmp_needs){
    for(int i=0; i<needs.size(); i++){
        if(needs[i] < tmp_needs[i] || needs[i] > tmp_needs[i])
            return false;
    }
    return true;
}
void dfs(int val, int index_one, int index_two, vector<int> tmp_needs){
    if(index_one+1 == needs.size()){
        return;
    }
    if(index_two+1 == special_num){
        return;
    }
    if(judge(tmp_needs)){
        ans.push_back(val);
        return;
    }
    else{
        return;
    }

    for(int i=0; i<needs.size(); i++){
        tmp_needs[i]++;
        dfs(val+single_price[i], index_one+1, index_two, tmp_needs);
        tmp_needs[i]--;
        dfs(val, index_one+1, index_two, tmp_needs);
    }

    for(int i=0; i<special_num; i++){
        for(int j=0; j<needs.size(); j++){
            tmp_needs[j] += special_item_num[i][j];
        }
        dfs(val+special_price[i], index_one, index_two+1, tmp_needs);
        
        for(int j=0; j<needs.size(); j++){
            tmp_needs[j] -= special_item_num[i][j];
        }
        dfs(val, index_one, index_two+1, tmp_needs);
    }
}

int main(){
    string str;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        single_price.push_back(stoi(s));
    }
    special_num = single_price.back();
    single_price.pop_back();

    for(int i=0; i<special_num; i++){
        get_special();
    }

    get_needs();

    vector<int> tmp_needs;
    for(int i=0; i<needs.size(); i++){
        tmp_needs.push_back(0);
    }
    dfs(0, 0, 0, tmp_needs);
    cout << ans.size() << endl;

    // cout << "\n single_price: ";
    // for(int i=0; i<single_price.size(); i++){
    //     cout << single_price[i] << ' ';
    // }
    // cout << endl;

    // cout << "\n special_nums: \n";
    // for(int i=0; i<special_item_num.size(); i++){
    //     for(int j=0; j<special_item_num[i].size(); j++){
    //         cout << special_item_num[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << "\n needs: ";
    // for(int i=0; i<needs.size(); i++){
    //     cout << needs[i] << ' ';
    // }
    // cout << endl;
    return 0;
}