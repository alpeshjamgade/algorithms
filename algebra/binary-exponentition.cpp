#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define mp make_pair
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b)
#define sdebug(n) cout << "\n' n = " << n << " '\n";

using namespace std;


ll binpow(ll base, ll index, ll mod)
{
	ll res = 1;
	while(index){
		if(index&1){
			res = (res*base)%mod;
		}
		base = (base*base)%mod;
		index >>= 1;
	}
	return res;
}

ll binpow_recur(ll base, ll index, ll mod)
{
	if(b == 0){
		return 1;
	}
	ll res = binpow_recur(base, index/2);
	if(index%2){
		return (res * res * base)%mod;
	}
	else{
		return (res*res)%mod;
	}
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  return 0;
}