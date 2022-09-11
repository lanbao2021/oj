#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
        // 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        // 记录合法的答案
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        // 考虑选择当前位置
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        // 考虑不选择当前位置
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};


int main(){
    int n, k;
    cin >> n >> k;
    Solution s = Solution();
    s.ans = s.combine(n, k);
    cout << '[';
    for(int i=0; i<s.ans.size(); i++){
        cout << "[";
        for(int j=0; j<s.ans[i].size(); j++){
            cout << s.ans[i][j];
            if(j+1 == k){
                cout << ']';
                break;
            }
            cout << ", ";
        }
        if(i+1 == s.ans.size())
            break;
        cout << ", ";
    }
    cout << ']';

    return 0;
}