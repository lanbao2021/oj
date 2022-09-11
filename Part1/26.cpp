#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans;

bool judge(string str){
    if(str.size()==1)
        return true;
    int i=0, j=str.size()-1;
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void dfs(string str, int idx, string S){
        if(idx == S.size()){
            if(str.back()==' ')
                return; // 咱去掉以','结尾的分割情况。如果忘了可以把这个条件判断取消注释观察一下
        // 将','作为分割符，得到多个子串，存到string类型的vector里面
        vector<string> tmp;
        string s="";
        for(int i=0; i<str.size(); i++){
            if(str[i]==' ')
                continue;
            if(str[i]==','){
                tmp.push_back(s);
                s="";
                continue;
            }
            s.push_back(str[i]);

        }
        tmp.push_back(s); // 最后一个s也要push进去
        // cout << tmp.size() << endl;
        // 从vector里面挨个取出子串，判断是否为回文，如果全是回文那么说明可以把str保存到ans
        bool flag = true;
        for (int i=0; i < tmp.size(); i++){
            if(judge(tmp[i]) == false){
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(str);
        }
        
        return;
    }
    dfs(str+S[idx]+", ", idx+1, S);
    dfs(str+S[idx], idx+1, S);
}

int main(){
    string S;
    string str="";
    cin >> S;
    dfs(str, 0, S);
    // cout << ans.size() << endl;
    cout << '[';
    for(int i=0; i<ans.size(); i++){
        cout << '[' << ans[i];
        if(i+1 == ans.size()){
            cout << ']';
            break;
        }
        cout << "], ";
    }
    cout << ']';
    return 0;
}