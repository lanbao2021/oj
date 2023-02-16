#include <iostream>
using namespace std;
int A[10001]={0};

int main(){
    //cout << "input length: ";
    int len;
    cin >> len;
    // 把cout去掉了提交就能成功
    //cout << "input elements(EOF): "; 
    int tmp;
    for(int i=0; i<len; i++){
        cin >> tmp;
        A[tmp]++;
    }
    int result;
    int split = len/2;
    for(int i=1; i<=10000; i++){
        if(A[i]>split){
            result=i;
            break;
        }
    }
    cout << result;
    return 0;
}