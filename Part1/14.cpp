#include <iostream>
#include <limits.h>
using namespace std;

int sum(int A[], int i, int j){
    int ans=0;
    for(;i<=j;i++){
        ans += A[i];
    }
    return ans;
}

int main(){
    int n;
    int A[50];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int max = INT_MIN;
    int tmp = 0;
    for(int len=1; len<=n; len++){
        for(int i=0; (i+len-1)<n; i++){
            tmp = sum(A, i, i+len-1);
            if(tmp > max){
                max = tmp;
            }
        }
    }
    cout << max << endl;
    return 0;
}