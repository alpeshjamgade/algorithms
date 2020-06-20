/*
	Given a set of items, each with a "weight" and a "value",
	determine the number of each item to include in a collection/knapsack
	so that -> "the total weight is less than or equal to a given limit"
	and "the total value is as large as possible".
*/
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

int knapsack_recur(int n, int W)
{
	if(n == 0 || W == 0){  // <-- if either n == 0 or W == 0, the profit will be 0;
		return 0;
	}
	if(dp[n][W] != -1){
		return dp[n][W];
	}
	if(wt[n-1] < W){ //  max(pick-the-item[reduced the capacity], dont pick the item);
		dp[n][W] = max(val[n-1]+knapsack_recur(n-1, W-wt[n-1]), knapsack_recur(n-1, W));
	}
	else{
		dp[n][W] = knapsack(n-1, W);
	}
	return dp[n][W];
}

int knapsack_iter(int n, int W)
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			if(j <= W){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+va;[i-1]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> W;
  for(int i = 0; i < n; i++){
  	cin >> val[i] >> wt[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << knapsack_recur(int n, W);
  return 0;
}