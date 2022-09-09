#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    // num = 7a + 5b + 2c;
    int ma, mb, mc; // a, b, c取值上限
    ma = num/7;
    mb = num/5;
    mc = num/2;
    int min=100;
    bool flag=false;
    for(int a=0; a<=ma; a++)
        for(int b=0; b<=mb; b++)
            for(int c=0; c<=mc; c++)
                if(num == 7*a + 5*b + 2*c){
                    flag=true;
                    if(min>(a+b+c))
                        min = a+b+c;
                }
    if(flag)
        cout << min;
    else
        cout << -1;
    return 0;
}