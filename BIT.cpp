int n;
vl bit;

void update(int i, ll val){
	while(i<=n+1){
		bit[i]+=val;
		i += (i&(-i));
	}
}

ll query(int i){
	ll ans = 0;
	while(i>0){
		ans+=bit[i];
		i-=(i&(-i));
	}
	return ans;
}
