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

int recursive(int ind,int x,int n,vector<int>&nums,vector<vector<int>>&dp){
    if(x<0)return 0;
    if(dp[ind][x]!=-1)return dp[ind][x];
    if(x==0)return 1;
    int ans =0;
    if(ind>=n)return 0;
    if(nums[ind]<=x){
        ans=recursive(ind,x-nums[ind],n,nums,dp);
    }
    ans =(ans + recursive(ind+1,x,n,nums,dp))%mod;
    return dp[ind][x]=ans%mod;
}
int iterative(int x,int n,vector<int>&nums,vector<vector<int>>&dp){
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=x;j++){
            int skipping = 0,picked = 0;
            skipping= dp[i+1][j];
            if(nums[i]<=j){
                picked = dp[i][j-nums[i]];
            }
            dp[i][j]=(picked+skipping)%mod;
        }
    }
    return dp[0][x];
}

int spaceOptimized(int x,int n,vector<int>&nums){
    vector<int>nextState(x+1,0); // dp[n][x]
    nextState[0]=1;  //similar dp[n][0]
    for(int i=n-1;i>=0;i--){
        vector<int>currentState(x+1,0);
        currentState[0]=1;
        for(int j=1;j<=x;j++){
            int skipping = 0,picked = 0;
            skipping= nextState[j]; //dp[i+1][j]
            if(nums[i]<=j){
                picked = currentState[j-nums[i]];
            }
            currentState[j]=(picked+skipping)%mod;
        }
        nextState = currentState;
    }
    return nextState[x];
}
void coinCombination2 (){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    //memset(dp,-1,sizeof(dp));
    int ans = spaceOptimized(x,n,coins);
    //for(int i=0;i<x;i++)cout<<dp[i]<<" ";
    cout<<ans<<endl;
}
int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){coinCombination2();}
}