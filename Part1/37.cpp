#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tmp;
    vector<int> nums;
    nums.push_back(1);
    while(cin >> tmp)
        nums.push_back(tmp);
    nums.push_back(1); // 首尾加个1，拓展成1+n+1的长度

    // 假设 dp[i][j] 表示开区间 (i,j) 内你能拿到的最多金币
    vector<vector<int> > dp(nums.size()+2, vector<int>(nums.size()+2, 0));

    // len表示开区间的长度，对每一个区间长度进行循环
    for(int len=3; len <= nums.size(); len++){
        // l表示开区间的左端点，l+len-1表示右端点
        for(int l=0; l <= nums.size() - len; l++){
            // k为开区间内的索引，代表区间最后一个被搓破的气球
            for(int k=l+1; k < l + len - 1; k++){
                int left = dp[l][k];
                int right = dp[k][l+len-1];
                int sum = left + right + nums[k] * nums[l] * nums[l+len-1];
                dp[l][l+len-1] = max(dp[l][l+len-1], sum); // 取金币最大值
            }
        }
    }

    cout << dp[0][nums.size() - 1] << endl;
    
    return 0;
}