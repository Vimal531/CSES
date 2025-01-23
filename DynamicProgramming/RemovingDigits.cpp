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

int iterative(int n){
    vector<int>ans(n+1,1e9);
    ans[0]=0;
    for(int i=1;i<=n;i++){
        string str = to_string(i);
        for(char c:str){
            int digit = c-'0';
            if(digit!=0){
                ans[i]=min(ans[i],1+ans[i-digit]);
            }
        }
    }
    return ans[n];
}
int recursion(int n){
    if(n==0)return 0;
    int temp = n;
    int ans = 1e9;
    if(dp[n]!=-1)return dp[n];
    while(temp){
        int digit = temp%10;
        temp/=10;
        if(digit == 0)continue;
        if(digit<=n)
        ans = min(ans,1+recursion(n-digit));
    }
    return dp[n]=ans;
}

void removingDigits(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<iterative(n)<<endl;
}

int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){removingDigits();}
}