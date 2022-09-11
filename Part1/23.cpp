#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans;
// 剩余的左括号数量要小于等于右括号数量，递归求解

void func(string str, int left, int right){
    if(left==0 && right==0){
        //cout << str << endl;
        ans.push_back(str);
        return;
    }
    if(left==right){
        
        func(str+"(", left-1, right);
    }
    else if(left < right){ // 这时加左右括号都行
        if(left > 0){
            
            func(str+"(", left-1, right); // 咱先加左括号
        }
        
        func(str+")", left, right-1);
    }
}



int main(){
    string str="";
    int n;
    cin >> n;

    func(str, n, n);

    cout << '[';
    bool last_flag=false;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i+1 == ans.size())
            break;
        cout << ", ";
    }
    cout << ']';
    

    return 0;
}