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



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // 1. check_parity(x) :-> return x&1?"odd":"even";
  // 2. gcd(a, b) :-> while(b^=a^=b^=a%=b);return a;
  // 3. check_power_of_2(x) :-> x&&!(x&(x-1));
  // 4. swap(a, b) :-> a^=b;b^=a;a^=b;
  // 5. max(x, y) = x^((x^y)&-(x<y));
  // 6. min(x, y) = y^((x^y)&-(x<y));

  return 0;
}

