#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tmp;
    vector<int> nums;
    while(cin >> tmp)
        nums.push_back(tmp);
    
    int n = nums.size();
    
    if(n==1){
        cout << "true" << endl;
        return 0;
    }

    if(nums[0]==0){
        cout << "false" << endl;
        return 0;
    }
        
    for(int i=1; i<n; i++){
        if(nums[i]==0){
            bool can = false;
            int j=i-1;
            while(j>=0){
                if(nums[j]+j > i){
                    can = true;
                    break;
                }
                j--;
            }
            if(!can){
                cout << "false" << endl;
                return 0;
            }
        }
    }
    cout << "true" << endl;
    return 0;
}