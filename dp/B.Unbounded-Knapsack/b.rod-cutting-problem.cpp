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

int n, L;
int cut[1001], pr[1001];
int dp[1001][1001];
int dp2[1001];

// int solve1(int n, int W)
// {
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j <= W; j++){
// 			if(i == 0){
// 				dp[i] = 0;
// 			}
// 			else{
// 				if(wt[i] M
// 						)
// 			}
// 		}
// 	}
// }
int solve_recur(int n, int L)
{
	if(n == 0 || L == 0){
		return 0;
	}
	if(dp[n][L] != -1){
		return dp[n][L];
	}
	if(cut[n-1] <= L){
		dp[n][L] = max(solve_recur(n-1, L)+cut[n-1], solve_recur(n-1, L)); 
	}
	else{
		dp[n][L] = solve_recur(n-1, L);
	}
	return dp[n][L];
}

int solve(int n, int L)
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= L; j++){
			if( cut[i-1] >= j){
				dp[i][j] = max(dp[i-1][j], pr[i-1]+dp[i][j-cut[i-1]]); // <-- add the price, keep the index same, decrease the length by c[i-1];
	 		}
	 		else{
	 			dp[i][j] = dp[i-1][j];
	 		}
	 	}
	}
	return dp[n][L];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> L;
  for(int i = 0 ; i < n; i++){
  	cin >> cut[i] >> pr[i];
  }

  for(int i = 0; i <= n; i++){
  	dp[i][0] = 0;
  }
  for(int j = 1; j <= L; j++){
  	dp[0][j] = 1;
  }
  cout << solve(n, L);
  return 0;
}