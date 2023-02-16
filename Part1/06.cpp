#include <iostream>
#include <vector>

using namespace std;

int func(char str[], int left, int right, int k){
    if(left > right) return 0;
    if((right-left+1) < k) return 0;
    vector<int> num(26, 0);
    int split=right; 
    bool allok=true;
    for(int i=left; i<=right; i++) num[str[i]-'a']++;
    for(int i=left; i<=right; i++) if(num[str[i]-'a'] < k) { split=i; allok=false; break; }
    if(allok) return right-left+1; // 最后结果
    int leftmax = func(str, left, split-1, k);
    int rightmax = func(str, split+1, right, k);
    
    if(leftmax > rightmax){
        return leftmax;
    }
    else{
        return rightmax;
    }

}

int main(){
    char ch[10000];
    cin >> ch;

    int k;
    cin >> k;
    
    int len=0;
    for(int i=0; ch[i]!='\0'; i++)
        len++;

    if(k<=1){
        cout << len;
        return 0;
    }
    int result = func(ch, 0, len-1, k);
    cout << result;

    return 0;
}