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
int recursion(int i,int j, int n, vector<int>&nums){
    if(i==j)return nums[i];
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j] = max(nums[i]-recursion(i+1,j,n,nums),nums[j]-recursion(i,j-1,n,nums));
}

void removalGame(){
    int n;
    cin>>n;
    vector<int>nums(n);
    int sum =0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    int ans = recursion(0,n-1,n,nums);
    cout<<(ans+sum)/2<<endl;
}


int32_t main(){
    memset(dp,-1,sizeof(dp));
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){removalGame();}
}