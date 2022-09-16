// Question Link: https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define pb push_back
#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vvvl vector<vector<vector<ll>>>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define ss second
#define ff first
#define rep(i,a,b) for(int i = a; i<b; i++)
#define ppi pair<int,int>
using namespace std;
 
const ll MAX = 1e15;
const ll MIN = -1*MAX;
const int MAX2 = 1e7;
const int MIN2 = -MAX2;
const int MOD = 1e9+7;
int n;
vi par;
vi sz;
 
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
 
bool Union(int a, int b){
	a = f(a);
	b = f(b);
	if(a == b)return false;
	if(sz[a]>sz[b]){
		swap(a,b);
	}
	par[a] = b;
	sz[b]+=sz[a];
	return true;
}
 
bool myComp(const vi &a, const vi &b){
	return a[2]<b[2];
}
 
void solve(){
	// minimum spanning tree using union find (DSU: Disjoint set union)
	// parent array and sz array
	cin>>n;
	int m; cin>>m;
	vvi g;
	rep(i,0,m){
		int a,b,c; cin>>a>>b>>c;
		g.pb({a,b,c});
	}
	par.resize(n+1);
	sz.resize(n+1,1);
	for(int i = 1; i<n+1; i++){
		par[i] = i;
	}
	int cnt = 1;
	sort(g.begin(),g.end(),myComp);
	ll cost = 0;
	for(auto e:g){
		bool temp = Union(e[0],e[1]);
		cnt+=temp;
		cost+=temp*e[2];
	}
	if(cnt!=n){
		cout<<"IMPOSSIBLE"<<endl;return;
	}
	cout<<cost<<endl;
}
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t = 1; 
	
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
