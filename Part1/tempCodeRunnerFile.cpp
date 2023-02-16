#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    return a%b == 0 ? b : gcd(b, a%b);
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if(a + b < c){
        cout << "false" << endl;
        return 0;
    }

    if(a == 0 || b == 0){
        if(c == 0 || a + b == c){
            cout << "true" << endl;
        }
        cout << "false" << endl;
        return 0;
    }
    
    if(a==b && c%a==0){
        cout << "true" << endl;
        return 0;
    }

    if(a<b){
        swap(a, b);
    }

    if(c % gcd(a,b) == 0){
        cout << "true" << endl;
        return 0;
    }
    cout << "false" << endl;

    return 0;
}