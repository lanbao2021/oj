#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
vector<string> ans;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void dfs(string str, int idx, vector<int>& nums){
    if(str.size()>=k || idx>=n){
        if(str.size()==k){
            for(int i=0; i<k; i++){
                cout << str[i];
                if(i+1 == k)
                    break;
                cout << ' ';
            }
            cout << endl;
        }
        return;
    }
    dfs(str+char(nums[idx]+'0'), idx+1, nums);
    dfs(str, idx+1, nums);
}


int main(){
    vector<int> nums;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        nums.push_back(i);
    }
    string str="";
    dfs(str, 0, nums);
    return 0;
}