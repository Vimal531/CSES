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


int dp[1000001][2];

void countingTowers(){
    int n;
    cin>>n;
    dp[n][0]=dp[n][1]=1;
    for(int i=n-1;i>=1;i--){
        //dp[i][0]->number of ways to fill grid from ith row to (n-1)th row where there is a horizontal block is extending from (i-1)th row
        dp[i][0]=(2ll*dp[i+1][0]+dp[i+1][1])%mod;
        //dp[i][1]->number of ways to fill grid from ith row to (n-1)th row where there are two vertical block is extending from (i-1)th row
        dp[i][1]=(4ll*dp[i+1][1]+dp[i+1][0])%mod;
    }
    cout<<(dp[1][0]+dp[1][1])%mod<<endl;
}
int32_t main(){
    memset(dp,0,sizeof(dp));
    fast_stream();
    // prime();
    //cal();
    int t=1;
    cin>>t;
    while(t--){countingTowers();}
}