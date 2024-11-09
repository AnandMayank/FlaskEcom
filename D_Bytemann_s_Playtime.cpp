#include "bits/stdc++.h"
#define int long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define all(v) v.begin(),v.end()
#define Mod 1000000007
using namespace std;
/* Fear says "WHAT IF", Faith says "EVEN IF" */
 
const int N = 2e5+10;
int dp[N]; 
vector<vector<int>> store; 
vector<pair<int,int>> child; 
 
int func(int i) {
  int leftdrop=store[i][0]; 
  int rightdrop=store[i][0];
  if(child[i].first!=-1) {
    int l=child[i].first; 
    leftdrop-=store[l][0]; 
    if(dp[l]==-1) func(l);
    leftdrop=max(leftdrop,dp[l]);
  } 
  if(child[i].second!=-1) {
    int r=child[i].second; 
    rightdrop-=store[r][0]; 
    if(dp[r]==-1) func(r);
    rightdrop=max(rightdrop,dp[r]);
  }
 
  return dp[i]=min(leftdrop,rightdrop);
}
 
void solve(){
  int n; cin>>n; 
  store.clear(); store.resize(n);
  for(int i=0; i<n; i++) dp[i] = -1;
  for(int i=0; i<n; i++){
    int h,l,len; cin>>h>>l>>len; 
    store[i].push_back(h); 
    store[i].push_back(l); 
    store[i].push_back(len);
    store[i].push_back(i);
  }
  sort(store.begin(),store.end()); 
  child.clear(); child.assign(n,{-1,-1});
  set<pair<int,pair<int,int>>> rem;
  for(int i=n-1; i>=0; i--) {
    int l=store[i][1]; 
    int r=store[i][1]+store[i][2];
    auto itr=rem.lower_bound({l,{-1,-1}});
 
    while(itr!=rem.end() && itr->first<=r) {
      int cur=itr->second.first; 
      if(itr->second.second==0) {
        child[cur].first=i; 
      }
      else child[cur].second=i; 
 
      itr=rem.erase(itr);
    }
    rem.insert({l,{i,0}}); 
    rem.insert({r,{i,1}});
  }
 
  vector<int> ans(n);
  for(int i=0; i<n; i++) {
    if(dp[i]==-1) func(i);
    ans[store[i][3]]=dp[i];
  }
 
  for(auto x:ans) cout<<x<<" ";
  cout<<'\n';
}
 
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve(); 
  return 0;
}