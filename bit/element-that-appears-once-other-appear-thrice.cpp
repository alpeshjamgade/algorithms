// Given an array where every element occurs three times, except one element ehich occurs only once.
// Find the element that occurs once.
// Expected time complexity is O(n) and O(1) extra space;

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
  int ones = 0;
  int twos = 0;
  int not_threes;
  int x;
  for(int i = 0; i < n; i++){
    cout << a[i] << ' ';
  }
  cout << '\n';
  for(int i = 0; i < n; i++){
    x = a[i];
    twos |= ones&x;
    ones ^= x;
    not_threes = ~(ones&twos);
    ones &= not_threes;
    twos &= not_threes;
  }
  return ones;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a[4] = {3, 3, 2, 3};
  cout << L(a, 4);
  return 0;
}

