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

using namespace std;

int lps(string s, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, 1));
  for(int i = 2; i <= n; i++){
    for(int j = 0; j < n-i+1; j++){
      int k = j+i-1;
      if(s[k] == s[j]){
        if(i == 2){
          dp[j][k] = 2;
        }
        else{
          dp[j][k] = 2 + dp[j+1][k-1];
        }
      }
      else{
        dp[j][k] = max(d[j][k-1], dp[j+1][k]);
      }
    }
  }
  return dp[0][n-1];
}

void solve()
{
  string s;
  cin >> s;
  int n = s.length();
  cout << lps(s, n);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tt;
  cin >> tt;
  while(tt--){
    solve();
    cout << '\n';
  }
  return 0;
}

