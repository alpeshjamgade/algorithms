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
int n, S = 0;
int arr[1001];
int dp[1001][1001];
int solve(int n, int S)
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= S; j++){
			if(arr[i-1] <= S){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	int mn = INT_MAX;
	for(int i = 0; i <= S/2; i++){
		if(dp[n][i]){
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

  cin >> n;
  for(int i = 0; i < n; i++){
  	cin >> arr[i];
  	S += arr[i];
  }

  for(int i = 0; i <= n; i++){
  	dp[i][0] = 1;
  }
  for(int j = 0; j <= S; j++){
  	dp[0][j] = 0;
  }
  cout << solve(n, S);
  return 0;
}