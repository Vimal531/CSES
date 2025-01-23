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


int dp[5001][5001];
void initialiseDp(int x){
    for(int i=0;i<5001;i++){
        for(int j=0;j<5001;j++){
            dp[i][j]=x;
        }
    }
    return;
}


void moneySums(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_set<int>ans;
    for(int i=0;i<n;i++){
        set<int>st;
        for(int x:ans){
            st.insert(x+nums[i]);
        }
        ans.insert(nums[i]);
        for(int x:st){
            ans.insert(x);
        }
    }
    cout<<ans.size()<<endl;
    nums.clear();
    for(int x:ans){
        nums.push_back(x);
    }
    sort(nums.begin(),nums.end());
    for(int x:nums){
        cout<<x<<" ";
    }
    cout<<endl;
}
int32_t main(){
    memset(dp,-1,sizeof(dp));
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){moneySums();}
}