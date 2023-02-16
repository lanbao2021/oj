#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int tmp;
    vector<int> ratings;
    while(cin >> tmp)
        ratings.push_back(tmp);
    
    int n = ratings.size();
    vector<int> left(n, 1), right(n, 1);

    for(int i=1; i<n; i++){
        if(ratings[i] > ratings[i-1])
            left[i] = left[i-1] + 1;
    }

    for(int i=n-1; i>0; i--){
        if(ratings[i-1] > ratings[i])
            right[i-1] = right[i] + 1;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans + max(left[i], right[i]);
    }

    cout << ans << endl;

    return 0;
}