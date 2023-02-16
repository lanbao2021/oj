#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int res;
    int n;
    
    void dfs(int val, int idx, vector<int>& nums){
        if (idx == n){
            // 终止递归
            res += val;
            return;
        }
        // 考虑选择当前数字
        dfs(val ^ nums[idx], idx + 1, nums);
        // 考虑不选择当前数字
        dfs(val, idx + 1, nums);
    }
    
    int subsetXORSum(vector<int>& nums) {
        res = 0;
        n = nums.size();
        dfs(0, 0, nums);
        return res;
    }
};


int main(){
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        data.push_back(stoi(s));
    }

    Solution solution = Solution();
    solution.subsetXORSum(data);
    cout << solution.res << endl;
    return 0;
}