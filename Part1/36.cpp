#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums;
    int tmp;
    while(cin >> tmp)
        nums.push_back(tmp);
    
    vector<int> dp(nums.size()+1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i=2; i < nums.size() + 1; i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
    }
    cout << dp[nums.size()] << endl;
    return 0;
}
