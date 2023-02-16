#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

// 涉及到递归，设置一些全局变量
vector<int> price_and_special_num;
vector<vector<int>> specials;
vector<int> needs;
map<vector<int>, int> needs_with_price;

void get_one_line_array(vector<int> &tmp){
    string str;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is >> s){
        tmp.push_back(stoi(s));
    }
}

int dfs(vector<int> needs){
    // 这并不是最基本的递归出口，而是一个剪枝策略
    // 当循环加深后难免有needs已经被求解过的情况
    // 所以可以记录下这些求解过的needs以空间换时间
    if(needs_with_price.count(needs) != 0)
        return needs_with_price[needs];

    // 对于每一个传入的needs都有一个上限price，就是不买大礼包的情况
    int MIN=0;
    for(int i=0; i < needs.size(); i++)
        MIN += needs[i] * price_and_special_num[i];

    // 接下去开始尝试购买大礼包让MIN的值尽量减小
    // 对于specials.size()个大礼包每一个都可以无限购买，所以要在循环里递归了
    for(int i=0; i < specials.size(); i++){
        // 每选择一种大礼包都需要对needs存档，这样才不影响下一次选择
        vector<int> tmp_needs = needs; 

        // 选择了一个大礼包后需要更新needs
        bool flag=true;
        for(int j=0; j < needs.size(); j++){
            // 如果有一个物品购买数量超出需求了咱就不能买这个
            if(specials[i][j] > needs[j]){ 
                flag = false;
                break;
            }
            // 没超出那就减去
            tmp_needs[j] -= specials[i][j];
        }
        if(flag == false)
            continue;

        // 下一个选什么咱不确定，需要继续for循环specials.size()次，以此类推...
        MIN = min(MIN, dfs(tmp_needs) + specials[i][needs.size()]);
    } 

    // 递归出口
    return needs_with_price[needs] = MIN;
}

int main(){
    // 第1行的最后一位数字会决定后面需要几行
    // 所以先读入一行数组，取出最后一位数字
    get_one_line_array(price_and_special_num);
    
    // 读入special_num行数组
    int special_num = price_and_special_num.back();
    for(int i=0; i<special_num; i++){
        vector<int> tmp;
        get_one_line_array(tmp);
        specials.push_back(tmp);
    }

    // 读入needs数组
    get_one_line_array(needs);
    
    cout << dfs(needs) << endl;

    return 0;
}