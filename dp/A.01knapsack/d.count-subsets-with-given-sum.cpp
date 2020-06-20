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

int n, S;
int arr[1001];
int dp[1001][1001];

int solve(int n, int S)
{
	for(int i = 0; i <= n; i++){
		dp[i][0] = 1;
	}
	for(int i = 1; i <= S; i++){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= S; j++){
			if(arr[i] <= j){
				dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][S];
}

int solve2(int n, int S)
{
	if(n == 0 ){
		return (int)(S == 0);
	}
	if( S == 0){
		return 1;
	}
	if(arr[n-1] <= S){
		dp[n][s] = solve2(n-1, S) + solve(n-1, S-arr[n-1]);
	}
	else{
		dp[n][S] = solve2(n-1, S);
	}
	return dp[n][S];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> S;
  for(int i = 0; i < n; i++){
  	cin >> arr[i];
  }
  cout << solve(n, S);
  cout << solve(n, S);

  return 0;
}