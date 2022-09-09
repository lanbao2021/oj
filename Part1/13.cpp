#include <iostream>
using namespace std;

int main(){
    char s[1000];
    cin >> s;

    int len=0;
    while(s[len] != '\0'){
        len++;
    }

    int arr[1000]={-1};

    for(int i=0, j=len-1; i<len && j>-1; i++, j--){
        arr[i] = s[i] - s[j];
    }

    for(int i=0; i<len; i++)
        cout << arr[i] << " ";
    cout << endl;

    int result_index[2]={0};
    int start=0, end=0;
    int max=0;

    for(int i=0; i<len; ++i){
        if(arr[i]==0){
            start=i;
            end=i;
        }
        else{
            continue;
        }
        for(int j=i+1; j<len; j++){
            if(arr[j] != 0){
                break;
            }
            end++;
        }
        if((end-start+1)>max){
            result_index[0]=start;
            result_index[1]=end;
        }
    }
    cout << result_index[0] << " " << result_index[1] << endl;
    return 0;
}