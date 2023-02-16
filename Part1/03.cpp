#include <iostream>
#include <vector>

using namespace std;

int main(){
    //vector<int> data = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> data;
    int len;
    cin >> len;
    int in=0;
    for(int i=0; i<len; i++){
        cin >> in;
        data.push_back(in);
    }
    int tmp = 0;
    int max_tmp = 0;
    for(int i=0; i<data.size(); i++){
        for(int j=i; j<data.size(); j++){
            tmp = tmp + data[j];
            if(tmp > max_tmp){
                max_tmp = tmp;
            }
        }
        tmp = 0; // 每次遍历清空
    }
    cout << max_tmp << endl;
    return 0;
}