#include <iostream>
using namespace std;

int five = 0;
int ten = 0;
int twenty = 0;
int bill[100000] = {0};

bool change5(){
    if(five>=1){
        five--;
        return true;
    }
    return false;
}

bool change15(){
    if(ten>=1 && five>=1){
        ten--;
        five--;
        return true;
    }
    if(five>=3){
        five -= 3;
        return true;
    }
    return false;
}
int main(){
    int tmp;
    int len=0;
    while(cin >> tmp){
        bill[len] = tmp;
        len++; // 最后会多加1，所以后面的for循环要用i<len，而不是i<=len
    }
    bool flag=true;

    for(int i=0; i<len; i++){
        if(bill[i] == 5){
            five++;
            continue;
        }
        else if(bill[i] == 10){
            ten++;
            if(!change5()){
                flag=false;
                break;
            }
            continue;
        }
        else{
            twenty++;
            if(!change15()){
                flag=false;
                break;
            }
            continue;
        }
    }
    if(flag)
        cout << "true";
    else
        cout << "false";
    return 0;
}