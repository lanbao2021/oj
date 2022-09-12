#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int sum(vector<int> &tmp, int begin, int end){
    int val=0;
    for(int i=begin; i<=end; i++){
        val += tmp[i];
    }
    return val;
}

void get_one_line(vector<int> &tmp){
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        tmp.push_back(stoi(s));
    }
}

int main(){
    vector<int> nums;
    get_one_line(nums);
    int k;
    cin >> k;

    int temp = sum(nums, 0, nums.size()-1) % k;
    if(temp != 0){
        cout << "false" << endl;
        return 0;
    }
    cout << "true" << endl;

    return 0;
}