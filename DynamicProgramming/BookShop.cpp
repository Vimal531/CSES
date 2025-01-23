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

int iterative(int &n,int &tot, vector<int>&cost, vector<int>&pages){
    vector<vector<int>>dp(n+1,vector<int>(tot+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=tot;j++){
            int skipping = dp[i+1][j];
            int picking = 0;
            if(j>=cost[i]){
                picking = pages[i]+dp[i+1][j-cost[i]];
            }
            dp[i][j]= max(skipping,picking);
        }
    }
    return dp[0][tot];
}

int recursion(int i,int tot, int n, vector<int>&cost, vector<int>&pages,vector<vector<int>>&dp){
    if(tot == 0)return 0;
    if(i>=n )return 0;
    int ans =0;
    if(dp[i][tot]!=-1)return dp[i][tot];
    if(cost[i]<=tot){
        ans = max (ans , pages[i]+recursion(i+1,tot-cost[i],n,cost,pages,dp));
    }
    ans = max (ans ,recursion(i+1,tot,n,cost,pages,dp));
    return dp[i][tot]=ans;
}

void bookShop(){
    int n,x;
    cin>>n>>x;
    vector<int>cost(n),pages(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    //vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    cout<<iterative(n,x,cost,pages)<<endl;
}
int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){bookShop();}
}