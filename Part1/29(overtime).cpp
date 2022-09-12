#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> perm;
int ans=0;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void dfs(vector<int> &nums, int start){
    if(start == nums.size()-1){
        // perm.push_back(nums);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%(i+1)==0 || (i+1)%nums[i]==0)
                continue;
            return;
        }
        ans++;
        return;
    }
    for(int i=start; i<nums.size(); ++i){
        swap(nums[i], nums[start]);
        dfs(nums, start+1);
        swap(nums[i], nums[start]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=1; i<=n; i++){
        nums.push_back(i);
    }

    
    dfs(nums, 0);

    // for(int i=0; i<perm.size(); i++){
    //     for(int j=0; j<perm[i].size(); j++){
    //         cout << perm[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i=0; i<perm.size(); i++){
    //     bool flag=true;
    //     for(int j=0; j<n; j++){
    //         // cout << perm[i][j] << "%" << j+1 << "=" << perm[i][j]%(j+1) << ", ";
    //         // cout << j+1 << "%" << perm[i][j] << "=" << (j+1)%perm[i][j] << endl;
    //         if(perm[i][j]%(j+1)==0 || (j+1)%perm[i][j]==0)
    //             continue;
    //         flag=false;
    //         break;
    //     }
    //     if(flag){
    //         ans++;
    //     }
        
    // }
    cout << ans << endl;
    return 0;
}