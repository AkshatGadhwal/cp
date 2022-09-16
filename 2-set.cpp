// Question Link: https://cses.fi/problemset/task/1684

// Solved Using DFS and two Adjency lists
// Not the easily understandable solution though

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
int n,m;
vvi adj1,adj2;
vvvi g;
vi arr;
vi vis;
// main elements: toping number and either it is 0 or 1
// g[i][0/1] :{x,0/1}
 
bool dfs(int i, vi &wish){
	if(arr[wish[0]] == wish[1]){
		vis[i] = 2;
		return true;
	}
	if(vis[i] == 1){
		return false;
	}
	vis[i] = 1;
	int x = wish[0];
	int want = wish[1];
	if(arr[x] == want){
		vis[i] = 2;
		return true;
	}else{
		arr[x] = want;
	}
	for(int j:(want?adj2[x]:adj1[x])){
		bool flag = true;
		for(auto w: g[j]){
			if(w[0] == x) continue;
			flag  = false;
			if(!dfs(j,w)){
				arr[x] = !want;
				vis[i] = 2;
				return false;
			}
		}
		if(flag){
			arr[x] = !want;
			vis[i] =2;
			return false;
		}
	}
	
	vis[i] = 2;
	return true;
}
 
void solve(){
	// what is connection between the whishes?
	// see if the graph is connected by using any of these two channels
	cin>>n;
	cin>>m;
	char plus = '+';
	char minus = '-';
	g.resize(n+1);
	adj1.resize(m+1);
	adj2.resize(m+1);
	arr.resize(m+1,1);
	vis.resize(n+1,0);
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<2; j++){
			char a; cin>>a;
			int x; cin>>x;
			g[i].pb({x,(a == plus?1:0)});
			if(a == plus){
				adj1[x].pb(i);
			}else{
				adj2[x].pb(i);
			}	
		}
	}
	
	for(int i = 1; i<n+1; i++){
		auto w1 = g[i][0], w2 = g[i][1];
		if(arr[w1[0]] != w1[1] and arr[w2[0]] != w2[1]){
			if(!dfs(i,w1) and !dfs(i,w2)){
				cout<<"IMPOSSIBLE"<<endl;
				return;
			}
		}
	}
	
	for(int i = 1; i<=m; i++){
		cout<<(arr[i]?plus:minus);
	}
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
