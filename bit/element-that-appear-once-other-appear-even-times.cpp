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


int L(int a[], int n)
{
  int res = 0;
  for(int i = 0; i < n; i++){
    res ^= a[i];
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a[10];
  for(int i = 0; i < 10; i++){
    cin >> a[i];
  }
  cout << L(a, 10);
  return 0;
}

