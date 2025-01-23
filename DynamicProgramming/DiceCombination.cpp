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
int check(int n){
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    int ans =0;
    for(int i=1;i<=6;i++){
        ans = (ans + check(n-i))%mod;
    }
    return dp[n]=ans%mod;
}
void diceCombination (){
    int n;
    cin>>n;
    int ans  = 0;
    vector<int>ans(n+1,0);
    ans[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(j<=i){
                ans[i]+=ans[i-j];
            }
        }
        ans[i]=ans[i]%mod;
    }
    cout<<ans[n]%mod<<endl;
}
int32_t main(){
    //fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){diceCombination();}
}