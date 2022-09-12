#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

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

    sort(nums.begin(), nums.end());

    if(nums.size()==1){
        cout << "false" << endl;
        return 0;
    }

    if(nums.size()==2){
        if(nums[0]==nums[1]){
            cout << "true" << endl;
            return 0;
        }
        cout << "false" << endl;
        return 0;
    }
    
    if(nums.size()==3){
        if(nums[0]+nums[1] == nums[2] || nums[1]+nums[2] == nums[0]){
            cout << "true" << endl;
            return 0;
        }
        cout << "false" << endl;
        return 0;
    }
    
    if(nums.size()==4){
        bool flag1 = nums[0] == nums[1]+nums[2]+nums[3];
        bool flag2 = nums[0]+nums[1] == nums[2]+nums[3];
        bool flag3 = nums[0]+nums[1]+nums[2] == nums[3];
        if(flag1 || flag2 || flag3){
            cout << "true" << endl;
            return 0;
        }
        cout << "false" << endl;
        return 0;
    }

    return 0;
}