#include <iostream>
#include <vector>
using namespace std;

int dfs(int i, int n, vector<bool> &visit){
    if(i>n) return 1;
    int ans=0;
    for(int j=1; j<=n; j++){
        if(!visit[j] && (i%j==0 || j%i==0)){
            visit[j] = true;
            ans += dfs(i+1, n, visit);
            visit[j] = false;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<bool> visit(n+1);
    for(int i=1; i<=n; i++){
        visit[i]=false;
    }
    cout << dfs(1, n, visit);
    
    return 0;
}