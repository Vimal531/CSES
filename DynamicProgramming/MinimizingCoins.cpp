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
int bda = 1000002;
int check1(int ind,int tot, int n , vector<int>&coins){
    if(tot==0)return 0;
    if(ind>=n || tot<0)return bda;
    if(dp[tot]!=-1)return dp[tot];
    return dp[tot]=min(1+check1(ind,tot-coins[ind],n,coins),check1(ind+1,tot,n,coins)); 
}

int iterative(int n,int sum,vector<int>&nums){
    dp[0]=0;
    for(int i=0;i<=sum;i++){
        if(i>0)dp[i]=1e9;
        for(int j=0;j<n;j++){
            if(nums[j]<=i){
                dp[i]=min(dp[i],dp[i-nums[j]]+1);
            }
        }
    }
    return dp[sum]==(1e9)?-1:dp[sum];
}

int check(int x,int n,vector<int>&nums){
    if(x==0)return 0;
    int ans =1e9;
    if(dp[x]!=-1)return dp[x];
    for(int i=0;i<n;i++){
        if(nums[i]<=x){
            ans = min(ans,1+check(x-nums[i],n,nums));
        }
    }
    return dp[x]=ans;
}
void minimizingCoins (){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int ans = check(x,n,coins);
    if(ans>1000000)cout<<-1<<endl;
    else{
        cout<<ans<<endl;
    }
}
int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){minimizingCoins();}
}