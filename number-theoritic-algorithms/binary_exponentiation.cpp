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

ll binpow_recur(ll a, ll b)
{
  if(b == 0){
    return 1;
  }
  ll res = binpow(a, b/2);
  if(b%2 == 0){
    return res *res *a;
  }
  else{
    return res*res;
  }
}

ll binpow_iter(ll a, ll b)
{
  ll res = 1;
  while(a){
    if(a&1){
      res = res * b;
    }
    b = b * b;
    a >>= 1;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  
  return 0;
}

