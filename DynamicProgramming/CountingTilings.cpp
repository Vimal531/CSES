#include<bits/stdc++.h>
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
#define all(x) x.begin(), x.end()
#define int long long
#define mod 1000000007
#define INF 5000000000000000000
#define sp(x,y) cout<<setprecision(y)<<x
#define ceil(a,b) ((a+b-1)/b)
void fast_stream(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int power(int a, int b){
    int res = 1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b=b>>1;
    }
    return res;
}
int powMod(int a,int b){
    int res=1;
    while(b){
        if(b&2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b>>1;
    }
    return res%mod;
}
int multiplyMod(int a,int b){
    int res=0;
    while(b){
        if(b&2){
            res=(res+a)%mod;
        }
        a=(a+a)%mod;
        b=b>>1;
    }
    return res%mod;
}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int gcd(int a,int b){if(b==0){return a;}return gcd(b,a%b);}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
bool myCmp(pair<int,string>&a,pair<int,string>&b){return a.second<b.second;}
bool isVowel(char c){
    if(c=='a'|| c=='A' || c=='e'|| c=='E' || c=='i'|| c=='I' || c=='o'|| c=='O'||c=='U' || c=='u'){
        return true;
    }
    return false;
}
vector<int>prime;
void AllPrimes(int n) {
    vector<int>primes(n,1);
    primes[0]=primes[1]=0;
    for(int i=2;i<n;i++){
        if(primes[i]==1){
            for(long long j=1ll*i*i;j<n;j+=i){
                primes[j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(primes[i]==1){
            prime.push_back(i);
            //cout<<i<<" ";
        }
    }
    return;
}
bool isPrime(int x){if(x<=1 ){return false;}for(int i=2;i*i<=x;i++){if(x%i==0){return false;}}return true;}
bool isPower2(int n){
    int x=n&(n-1);
    if(x==0){
        return 1;
    }
    return 0;
}
/**********************************************'Coding'******************************************************************/


/******************************************'Vimal Maury'***********************************************************/
int dp[1001][1<<10 +1];


void generatedAllMask(int currMask, int row , int nMask, int n, vector<int>&next_mask){
    if(row == n+1){
        next_mask.push_back(nMask);
        return;
    }
    if((currMask & (1<<row))!=0){
        generatedAllMask(currMask,row+1,nMask,n,next_mask);
    }
    if(row!=n){
        if((currMask & (1<<row))==0 && (currMask & (1<<(row+1)))==0){
            generatedAllMask(currMask,row+2,nMask,n,next_mask);
        }
    }
    if((currMask & (1<<row))==0)
    generatedAllMask(currMask,row+1,nMask + (1<<row),n,next_mask);
}


int countingTilings(int i,int mask,int n,int m){
    if(i==m+1){
        if(mask==0)return 1;
        return 0;
    }
    if(dp[i][mask]!=-1)return dp[i][mask];
    vector<int>next_mask;
    generatedAllMask(mask,1,0,n,next_mask);
    int ans = 0;
    for(auto currMask:next_mask){
        //cout<<currMask<<" ";
        ans = (ans + countingTilings(i+1,currMask,n,m))%mod;
    }
   // cout<<endl;
    return dp[i][mask]=ans%mod;
}
void solve(){
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<countingTilings(1,0,n,m)<<endl;
}
int32_t main(){
    fast_stream();
    int t=1;
    while(t--){
     solve();
    }
   return 0;
}
