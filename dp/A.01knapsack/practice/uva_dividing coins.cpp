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
int tt, m, S;
int a[100];
bool dp[101][101];


int solve(int m, int S)
{
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= S; j++){
			if(j <= S){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]] + a[i-1];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	int mn = INT_MAX;
	for(int i = 0; i <= S/2; i++){
		if(dp[m][i]){
			mn = min(mn, S-2*i);
		}
	}
	return mn;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> tt;
  while(tt--){
  	cin >> m;
  	S = 0;
  	for(int i = 0; i < m; i++){
  		cin >> a[i];
  		S += a[i];
  	}
  	for(int i = 0; i <= m; i++){
  		dp[i][0] = true;
  	}
  	for(int j = 1; j <= S; j++){
  		dp[0][j] = false;
  	}
  	cout << solve(m, S) << '\n';
  }
  return 0;
}	