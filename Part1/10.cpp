#include <iostream>
using namespace std;

int func(int m, int n){
    if(m<=0 || n<=0){
        return 0;
    }
    
    if(m==1 || n==1){
        return 1;
    }

    if(m==2 && n==2){
        return 2;
    }
    return func(m-1, n) + func(m, n-1);
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << func(m, n);
    return 0;
}
