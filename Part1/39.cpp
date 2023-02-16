#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    return a%b == 0 ? b : gcd(b, a%b);
}

bool judge(int a, int b, int c){
    if(a+b < c)
        return false;
    
    if(a==0 || b==0){
        return c==0 || a+b==c;
    }

    if(a<b)
        swap(a, b);

    if(c % gcd(a, b) == 0)
        return true;
    
    return false;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if(judge(a, b, c)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}