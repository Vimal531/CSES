#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
//#define int long long
#define endl '\n'
#define mod 1000000007
#define sp(x,y) cout<<setprecision(y)<<x
#define ceil(a,b) ((a+b-1)/b)
void fast_stream() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int dp[1000001];


void gridPaths(){
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        if(grid[0][i]=='*')break;
        ans[0][i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*')continue;
            ans[i][j]=(ans[i][j]+ans[i-1][j])%mod;
            if(j>0){
                ans[i][j]=(ans[i][j]+ans[i][j-1])%mod;
            }

        }
    }
    cout<<ans[n-1][n-1]<<endl;
    
}

int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){gridPaths();}
}