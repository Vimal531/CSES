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


int dp[100001][101];
vector<int>nums;
int n,m;

  //dp[ind][pre]->total number of prefixes of length `ind` that can be formed such that the last element of the prefix is `pre`
int recursion(int ind,int pre){
    if(ind>=n)return 1;
    if(ind>0 && nums[ind]!=0 && abs(pre-nums[ind])>1)return 0;
    if(pre!=-1 && dp[ind][pre]!=-1)return dp[ind][pre];
    int ans = 0;
    if(nums[ind]==0){
        for(int i=1;i<=m;i++){
            if(pre==-1){
                ans =(ans + recursion(ind+1,i))%mod;
            }
            else if(abs(pre-i)<=1){
                ans = (ans + recursion(ind+1,i))%mod;
            }
        }
    }
    else{
        ans =(ans + recursion(ind+1,nums[ind]))%mod;
    }
    return dp[ind][pre]=ans%mod;
}

int iterative(){
    memset(dp,0,sizeof(dp));
    //base case 

    for(int k=1;k<=m;k++){
        if(nums[0]==0 
        }
    }

    //dp[i][k] = dp[i-1][k-1]+dp[i-1][k]+dp[i-1][k+1]
    //dp[i][k]->no of prefixes of length i that can be formed such that the last elemnt of prefix is k
    for(int i=2;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(nums[i-1]!=0 && nums[i-1]!=k){
                dp[i][k]=0;
                continue;
            }
            for(int j=k-1;j<=k+1;j++){//j ->pre
                if(j<1 || j>m)continue;
                dp[i][k]= (dp[i][k]+dp[i-1][j])%mod;
            }
        }
    }
    int ans =0;
    for(int i=1;i<=m;i++){
        //cout<<dp[n][i]<<" ";
        ans = (ans + dp[n][i])%mod;
    }
    cout<<ans<<endl;
    return ans;
}

void arrayDescription(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<iterative()<<endl;
    nums.clear();
    return;
}

int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){arrayDescription();}
}