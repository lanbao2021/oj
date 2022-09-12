#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

int MIN = INT_MAX;

vector<int> single_price;
int special_num;
vector<int> special_price;
vector<vector<int>> special_item_num;
vector<int> needs;

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

bool judge(vector<int> &get_num){
    for(int i=0; i<needs.size(); i++){
        if(needs[i] != get_num[i])
            return false;
    }
    return true;
}
void dfs(int val, vector<int> get_num){
    if(val>=MIN){
        return;
    }
    if(judge(needs)){
        MIN = val;
        return;
    }
    else{
        return;
    }
    // choose single price, has 'single_price.size()' choice
    for(int i=0; i<single_price.size(); i++){
        val += single_price[i]; // choose it
        get_num[i]++;
        dfs(val, get_num);
        val -= single_price[i]; // drop it choose next
        get_num[i]--;
        dfs(val, get_num);
    }
    // choose a special_price
    for(int i=0; i<special_num; i++){
        // choose it
        val += special_price[i];
        for(int j=0; j<needs.size(); j++){
            get_num[i] += special_item_num[i][j];
        }
        dfs(val, get_num);

        // drop it choose next
        val -= special_price[i];
        for(int j=0; j<needs.size(); j++){
            get_num[j] -= special_item_num[i][j];
        }
        dfs(val, get_num);
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

    vector<int> get_num;
    for(int i=0; i<needs.size(); i++){
        get_num.push_back(0);
    }
    dfs(0, get_num);
    cout << MIN << endl;

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