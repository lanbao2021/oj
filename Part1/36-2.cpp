#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tmp;
    vector<int> nums;
    while(cin >> tmp)
        nums.push_back(tmp);

    int a = nums[0]; // 1
    int b = a>nums[1] ? a : nums[1]; // 2
    for(int i=2; i<nums.size(); i++){
        tmp = b;
        b = max(b, a+nums[i]);
        a = tmp;
    }
    
    cout << b << endl;
    return 0;
}