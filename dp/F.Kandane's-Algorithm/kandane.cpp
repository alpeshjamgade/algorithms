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

string s1, s2;
int dp[1001][1001];


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s1 >> s2;
  memset(dp, 0, sizeof(dp));
  return 0;
}