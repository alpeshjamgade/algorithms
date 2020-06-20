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

int n, W;
int val[1001], wt[1001];

int dp[1001][1001];

int solve1(int n, int W)
{
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			if(wt[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], dp[i][j-wt[i-1]]+val[i-1]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= W; j++){
			cout << dp[i][j] << "  ";
		}
		cout << '\n';
	}
	return dp[n][W];
}

int dp1[1001];
int solve2(int n, int W)
{
	for(int i = 0; i <= W; i++){
		for(int j = 0; j < n; j++){
			if(wt[j] <= i){
				dp1[i] = max(dp1[i], dp1[i-wt[j]]+val[j]);
			}
		}
	}
	for(int i = 0; i <= W; i++){
		cout << dp1[i] << ' ';
	}
	cout << '\n';
	return dp1[W];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> W;
  memset(dp, 0, sizeof(dp));
  memset(dp1, 0, sizeof(dp1));
  for(int i = 0; i < n; i++){
  	cin >> val[i] >> wt[i];
  }
  cout << solve1(n, W) << '\n';
  cout << solve2(n, W) << '\n';


  return 0;
}