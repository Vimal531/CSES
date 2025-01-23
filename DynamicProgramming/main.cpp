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
int power(int a,int b){int res=1;
while(b>0){if(b%2){res=(res*a)%mod;--b;}else{a=(a*a)%mod;b=b>>1;}}return res%mod;}
int power1(int a,int b){int res=1;
while(b>0){if(b%2){res=(res*a);--b;}else{a=(a*a);b=b>>1;}}return res;}
int multiply(int a,int b){int res=0;
while(b>0){if(b%2){res=(res+a)%mod;}a=(a+a)%mod;b=b>>1;}return res%mod;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int gcd(int a,int b){if(b==0){return a;}return gcd(b,a%b);}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
bool myCmp(pair<int,string>&a,pair<int,string>&b){return a.second<b.second;}

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

void solve1 (){
    int  n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int tar;
    cin>>tar;
    sort(nums.begin(),nums.end());
    int ans =0;
    set<int>s;
    s.insert(ans);
    for(int i=0;i<n;i++){
        set<int>st;
        for(auto x:s){
            int ns = x+nums[i];
            if(ns<=tar){
                st.insert(ns);
                if(ns>ans){
                    ans = ns;
                }
            }
        }
        for(auto x:st){
            s.insert(x);
        }
    }
    cout<<ans<<endl;
}
int solve2(){
}
int32_t main(){
    fast_stream();
    // prime();
    //cal();
    int t=1;
    //cin>>t;
    while(t--){solve2();}
}