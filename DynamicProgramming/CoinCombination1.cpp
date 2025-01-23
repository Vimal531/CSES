#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
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
int recursive(int x,int n,vector<int>&nums){
    if(x==0)return 1;
    int ans =0;
    if(dp[x]!=-1)return dp[x];
    for(int i=0;i<n;i++){
        if(nums[i]<=x){
            ans = (ans+recursive(x-nums[i],n,nums))%mod;
        }
    }
    return dp[x]=ans%mod;
}
int check(int x,int n,vector<int>&nums){
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(nums[j]<=i){
                dp[i]=(dp[i]+dp[i-nums[j]])%mod;
            }
        }
    }
    return dp[x]%mod;
}
void coinCombination1 (){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int ans = check(x,n,coins);
    cout<<ans<<endl;
}
int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){coinCombination1();}
}