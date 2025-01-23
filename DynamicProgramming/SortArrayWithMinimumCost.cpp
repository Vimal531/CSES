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

int dp[1000][10000];
int check(int ind, int low, int high , vector<int>&nums){
    int n = nums.size();
    if(ind>=n) return 0;
    int ans = INT_MAX;
    if(dp[ind][low]!=-1)return dp[ind][low];
    for(int i=low;i<=high;i++){
        ans = min(ans , abs(nums[ind]-i)+check(ind+1,i,high,nums));
    }
    return dp[ind][low]=ans;
}

void sortArrayWithMinimumCost (){
   memset(dp,-1,sizeof(dp));
   int n ;
   cin>>n;
   vector<int>nums(n);
   for(int i=0;i<n;i++){
    cin>>nums[i];
   }
   int low = *min_element(nums.begin(),nums.end());
   int high = *max_element(nums.begin(),nums.end());
   int first = check(0,low,high,nums);
   reverse(nums.begin(),nums.end());
   int second = check(0,low,high,nums);
   cout<<min(first,second)<<endl;
}
int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){sortArrayWithMinimumCost();}
}