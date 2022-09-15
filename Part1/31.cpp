#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <map>
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

class Solution {
public:
    vector<int> needs_;
    vector<int> price_;
    vector<vector<int> > special_;
    int n;
    map<vector<int>, int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        price_ = price;
        special_ = special;
        n = needs.size();
        return dfs(needs);
    }
    int dfs(vector<int> needs) {
        if (dp.count(needs) != 0)
            return dp[needs]; // 这不是最后出口，而是一个剪枝的策略。

        int Min = 0;
        for (int i = 0; i < needs.size(); i++)
            Min += needs[i] * price_[i];

        for (int i = 0; i < special_.size(); i++) {
            vector<int> nextNeeds = needs;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (special_[i][j] > nextNeeds[j])
                    flag = false; // 这里直接break进入下一个special即可
                nextNeeds[j] -= special_[i][j];
            }
            if (!flag)
                continue;
            Min = min(Min, dfs(nextNeeds) + special_[i][n]);
        }
        return dp[needs] = Min;
    }
};


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

    Solution solution = Solution();
    cout << solution.shoppingOffers(single_price, special_item_num, needs) << endl;
    return 0;
}