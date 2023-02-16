#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tmp;
    vector<int> nums;
    while(cin >> tmp){
        nums.push_back(tmp);
    }

    int n = nums.size();
    if(n<3){
        cout << n << endl;
        return 0;
    }

    int left=0, mid=1, right=2;
    int ans=2;
    while(right<n){
        if((nums[mid]>nums[left] && nums[mid]>nums[right]) || (nums[mid]<nums[left] && nums[mid]<nums[right])){
            ans++;
            left=mid;
            mid=right;
            right++;
        }
        else{
            mid++;
            right++;
        }
    }
    cout << ans << endl;
    return 0;
}