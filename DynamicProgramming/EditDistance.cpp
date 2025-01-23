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


int dp[5001][5001];
void initialiseDp(int x){
    for(int i=0;i<5001;i++){
        for(int j=0;j<5001;j++){
            dp[i][j]=x;
        }
    }
    return;
}
int recusion(int i,int j,string &s , string &t){
    int n = s.length();
    int m = t.length();
    if(i>=n)return (m-j);
    if(j>=m)return (n-i);
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=recusion(i+1,j+1,s,t);
    }
    else{
        return dp[i][j]=1+min(recusion(i,j+1,s,t),min(recusion(i+1,j+1,s,t),recusion(i+1,j,s,t)));
    }
}

int iterative(string &s, string &t){
    int n = s.length();
    int m = t.length();
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+dp[i-1][j-1]; // replacing the char
            }

            dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
            dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
            //cout<<dp[i][j]<<" ";
        }
        ///cout<<endl;
    }
    return dp[n][m];
}

void editDistance(){
    string s,t;
    cin>>s>>t;
    //cout<<recusion(0,0,s,t)<<endl;
    initialiseDp(1e9);
    cout<<iterative(s,t)<<endl;
}
int32_t main(){
    memset(dp,-1,sizeof(dp));
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){editDistance();}
}