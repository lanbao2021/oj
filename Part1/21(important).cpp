#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
    //字符串长度小于等于k的时候返回0
        if(num.size()<=k) return "0";
     //开始一次k循环删一个
    for(;k>0;k--){
    for(int i=0;i<num.size();i++)
        if(num[i]>num[i+1]){
            for(int j=i;j+1<num.size();j++)
                num[j]=num[j+1];
            break;
        }
    num.pop_back(); // 灵魂所在，直接原地修改
    }
    //开头有0删了
    while(num.size()>1 && num[0] == '0'){
        for(int j=0;j+1<num.size();j++)
                num[j]=num[j+1];
        num.pop_back(); // 又来0.0
    }
        return num;
    }
};

int main(){
    string num;
    int k;
    cin >> num >> k;
    Solution s = Solution();
    cout << s.removeKdigits(num, k) << endl;
    return 0;
}