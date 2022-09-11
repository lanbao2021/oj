#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        data.push_back(stoi(s));
    }

    vector<int> h=data;
    sort(h.begin(), h.end(), greater<int>());

    int area=0, max_area=0;

    for(int i=0; i<h.size(); i++){
        int left=-1, right=-1;
        bool left_max_flag=false;
        for(int j=0; j<data.size(); j++){
            if(left_max_flag==false && data[j]>=h[i]){
                left_max_flag = true; // 尽可能左
                left = j;
                continue;
            }
            if(data[j] >= h[i]){
                right = j; // 尽可能右
            }
        }
        if(right != -1){
            // left肯定不会-1
            area = h[i] * (right - left);
            if(area > max_area){
                max_area = area;
            }
        }
    }

    cout << max_area << endl;
    return 0;
}