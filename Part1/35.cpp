#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
    int n;
    //cout << "input:";
    cin >> n;
    
    if(n<4){
        cout << n-1 << endl;
        return 0;
    }
    int a = n/3;
    int b = n%3;
    int ans;
    if(b==0)
        ans = pow(3, a);
    if(b==1)
        ans = pow(3, a-1)*4;
    if(b==2)
        ans = pow(3, a)*2;
    cout << ans << endl;
    return 0;
}