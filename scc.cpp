//question link: https://cses.fi/problemset/task/1682



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
vi vis1,vis2;
vvi adj1,adj2;
 
void dfs(int i, vi &vis, vvi &adj){
	vis[i] = 1;
	for(int j:adj[i]){
		if(!vis[j]){
			dfs(j,vis,adj);
		}
	}
}
 
void solve(){
	// check if the graph is strongly connected
	cin>>n;
	int m; cin>>m;
	adj1.resize(n+1);
	adj2.resize(n+1);
	vis1.resize(n+1,0);
	vis2.resize(n+1,0);
	rep(i,0,m){
		int a,b; cin>>a>>b;
		adj1[a].pb(b);
		adj2[b].pb(a);
	}
	dfs(1,vis1,adj1);
	dfs(1,vis2,adj2);
	for(int i = 1; i<n+1; i++){
		if(!vis1[i] || !vis2[i]){
			cout<<"NO"<<endl;
			if(!vis1[i]){
				cout<<1<<" "<<i<<endl;
			}else{
				cout<<i<<" "<<1<<endl;
			}
			return;
		}
	}
	cout<<"YES"<<endl;
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
