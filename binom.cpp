
// code snippit to calculate binomial coefficient

int mod;

int pow(n,k){
  long long res = 1;
  while(k){
    if(k & 1){
      res*=n;
      res%=mod;
    }
    if(k >>= 1){
      n*=n;
      n%=mod;
    }
  }
  return res;
}

int inv(int n){
  return pow(n,mod-2);  
}

int fac[n]
int ivf[n]
fact[0] = 1;
for(int i = 1; i<=n; i++) fac[i] = fac[i-1] * i % mod;
ivf[n] = inv(fac[n]);
for(int i = n-1; i>=0; i--) ivf[i] = ivf[i+1] * ( i + 1 ) % mod ;

int binom(int x, int y) {
  if (x < 0 || y < 0 || x < y) return 0;
  return fac[x] * ivf[y] * ivf[x - y];
}
