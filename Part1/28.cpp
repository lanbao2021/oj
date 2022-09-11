#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> ans;

void fun(string str, int idx, vector<string> &S){
    if(idx==S.size()){
        // cout << str << endl;
        ans.push_back(str);
        return;
    }
    fun(str+S[idx][0], idx+1, S);
    fun(str+S[idx][1], idx+1, S);
    fun(str+S[idx][2], idx+1, S);
    if(S[idx].size()==4)
        fun(str+S[idx][3], idx+1, S);
    return;
}

int main(){
    vector<string> S;
    string s2="abc", s3="def", s4="ghi", s5="jkl", s6="mno";
    string s7="pqrs", s8="tuv", s9="wxyz";
    string tmp;
    cin >> tmp;
    sort(tmp.begin(), tmp.end());
    // cout << tmp << endl;
    for(int i=0; i<tmp.size(); i++){
        if(tmp[i]=='2'){
            S.push_back(s2);
            continue;
        }
        if(tmp[i]=='3'){
            S.push_back(s3);
            continue;
        }
        if(tmp[i]=='4'){
            S.push_back(s4);
            continue;
        }
        if(tmp[i]=='5'){
            S.push_back(s5);
            continue;
        }
        if(tmp[i]=='6'){
            S.push_back(s6);
            continue;
        }
        if(tmp[i]=='7'){
            S.push_back(s7);
            continue;
        }
        if(tmp[i]=='8'){
            S.push_back(s8);
            continue;
        }
        if(tmp[i]=='9'){
            S.push_back(s9);
            continue;
        }
    }
    string str="";
    fun(str, 0, S);
    cout << '[';
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i+1 == ans.size())
            break;
        cout << ", ";
    }
    cout << ']' << endl;
    
    return 0;
}