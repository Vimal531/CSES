#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define endl '\n'
#define mod 1000000007
#define sp(x,y) cout<<setprecision(y)<<x
#define ceil(a,b) ((a+b-1)/b)
//#pragma GCC optimize("-O2")
void fast_stream() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int dp[501][65000];


int recursion(int i,int targetSum,int n,vector<int>&nums){
    if(targetSum==0)return 1;
    if(i==n || targetSum<0)return 0;
    if(dp[i][targetSum]!=-1)return dp[i][targetSum];
    return dp[i][targetSum]=(recursion(i+1,targetSum-nums[i],n,nums)+recursion(i+1,targetSum,n,nums))%mod;
    
}

void twoSets2(){
    int n;
    cin>>n;
    int targetSum = (n*(n+1));
    if(targetSum%4!=0){
        cout<<0<<endl;
        return;
    }
    targetSum/=4;
    vector<int>nums;
    for(int i=1;i<=n;i++){
        nums.push_back(i);
    }
    int ans = recursion(0,targetSum,n-1,nums);
    cout<<(ans)%mod<<endl;
}
int32_t main(){
    memset(dp,-1,sizeof(dp));
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){twoSets2();}
}