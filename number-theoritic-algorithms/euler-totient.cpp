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


int phi1(int n)
{
  int cnt = 0;
  int tmp = n;
  for(int i = 2; i *i <= n; i++){
    if(tmp%i == 0){
      cnt++;
      while(tmp%i == 0){
        tmp /= i;
      }
    }
  }
  if(n > 1){
    cnt++;
  }
  return cnt;
}

int phi2(int n)
{
  int res = n;
  int tmp = n;
  for(int i = 2; i*i <= n; i++){
    if(tmp%i == 0){
      while(tmp%i == 0){
        tmp /= i;
      }
      res -= res/i;
    }
  }
  if(n > 1){
    res -= res/n;
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

