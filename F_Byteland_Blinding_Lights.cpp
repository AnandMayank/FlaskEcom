#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set; 
using namespace std;
int mod=998244353;
#define endl "\n"
#define ll int64_t
#define int long long
#define ff  first
#define ss second
#define f(i,a,b) for(int i(a);i<b;i++)
#define rep(i,n) for(int i(0);i<n;i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define pres(x) cout<<fixed; cout<<setprecision(x);
#define watch(x) cout<<(#x)<<" is "<<x<<"\n";
#define out(x) cout<<x<<"\n";
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
int inf = 1e18;
#define pdd pair<double, double>
#define ld long double
#define ar array
int gcd(int a,int b){return (b==0) ? a:gcd(b,a%b);} 
int power(int a,int b){
    int ans=1;
    while(b!=0){
        if(b&1){ans=(ans*a)%mod;b--;}
        a=(a*a)%mod;b/=2;
    }
    return ans%mod;}
int invmod(int n){
    int ans=1;
    ans=power(n,mod-2);
    return ans;}

int min(int a,int b){return (a<b) ? a:b;}
int max(int a,int b){return (a>b) ? a:b;}

// int fact[100000];
// int infact[100000];
long double findRoots(int a, int b, int c)
{
    // Calculate the discriminant d = b^2 - 4ac
    int d = b * b - 4 * a * c;

    // If d is negative, the roots are complex and there is no real solution
    if(d < 0) 
        return -1;

    // Calculate the square root of the discriminant
    long double sqrt_val = sqrtl(abs(d));

    // Calculate the first root using the positive square root
    long double p = (long double)(-b + sqrt_val) / (long double)(2 * a);

    // Calculate the second root using the negative square root
    long double q = (long double)(-b - sqrt_val) / (long double)(2 * a);

    // Initialize ans to the first root
    long double ans = p;

    // If the second root q is non-negative and smaller than p, update ans to q
    if(q >= 0 && q < p)
    {
        ans = q;
    }

    // Return the smallest non-negative root
    return ans;
}

void solve(){   
    int a,b,v1,v2;cin>>a>>b>>v1>>v2;
    int n;cin>>n;
    vpi arr(n);
    map<pi,int> m;
    f(i,0,n){
        cin>>arr[i].first>>arr[i].second;
        m[arr[i]]=i;
    }
    sort(all(arr));
    int ind=-1;
    long double time=1000;
    f(i,0,n)
    {
        int x=arr[i].ff;int y=arr[i].ss;
        long double t=findRoots(v1*v2 , v1*y+a*v2-v1*b-x*v2,b*x+a*y-a*b);
        if(t>=0 && (t<time) && abs(t-time) > 1e-10){
            time=t;
            ind=m[arr[i]]+1;
        }
    }
    out(ind)

}
    

signed main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ; 
    freopen("output.txt","w",stdout);
    #endif
    // fact[0]=1;
    // infact[0]=invmod(fact[0]);
    // f(i,1,200005){
    //  fact[i]=fact[i-1]*i;fact[i]%=mod;
    //  infact[i]=invmod(fact[i]);
    // }

    int tc=1;
    cin>>tc;
    while(tc--){
    solve();
    }
  
}
