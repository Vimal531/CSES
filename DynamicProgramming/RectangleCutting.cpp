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

int recursion(int a,int b){
    if(a==b)return 0;
    if(a==1)return b-1;
    if(b==1)return a-1;
    int ans = INT_MAX;
    if(dp[a][b]!=-1)return dp[a][b];
    for(int i=1;i<a;i++){
        ans = min(ans,1+recursion(i,b)+recursion(a-i,b));
    }
    for(int i=1;i<b;i++){
        ans = min(ans,1+recursion(a,i)+recursion(a,b-i));
    }
    return dp[a][b]=ans;
}

//dp[i][j]=  minimum number of cuts to make i*j rectanble into squares
int iterative(int a,int b){
    vector<vector<int>>ans(a+1,vector<int>(b+1,1e9));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                ans[i][j]=0;
                continue;
            }
            //makingn vertical cut 
            for(int v=1;v<=i-1;v++){
                ans[i][j]=min(ans[i][j],1+ans[v][j]+ans[i-v][j]);
            }
            //horizontal cut 
            for(int h=1;h<=j-1;h++){
                ans[i][j]=min(ans[i][j],1+ans[i][h]+ans[i][j-h]);
            }
        }
    }
    return ans[a][b];
}
void rectangleCutting(){
    int a,b;
    cin>>a>>b;
    //cout<<recursion(a,b)<<endl;
    cout<<iterative(a,b)<<endl;
}
int32_t main(){
    memset(dp,-1,sizeof(dp));
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){rectangleCutting();}
}