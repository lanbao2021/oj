#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
    //先判断字符串长度小于等于k的时候不禁删，我直接返回的0可能题目设置有问题，我感觉小于的时候应该返回""
        if(num.size()<=k) return "0";
     //开始一次k循环删一个
    for(;k>0;k--){
    for(int i=0;i<num.size();i++)
        if(num[i]>num[i+1]){
            for(int j=i;j<num.size()-1;j++)
                num[j]=num[j+1];
            break;
        }
    num.pop_back();
    }
    //开头有0删了
    while(num.size()>1 && num[0] == '0'){
        for(int j=0;j<num.size()-1;j++)
                num[j]=num[j+1];
         num.pop_back();
    }
        return num;
    }
};

int main(){
    string num;
    int k;
    num = "284596392560823753281987661852081446173776822522323539075168833664017056918317290993749225383926039727703640926205909919806185334568806082298349662997987818886906579102100707277990336833107163554103790620507865617788476427750941146001437411243084268131171608264431472815387854609847625666291277363466945484979788686019509121632";
    k=175;
    Solution s = Solution();
    cout << s.removeKdigits(num, k) << endl;
    return 0;
}