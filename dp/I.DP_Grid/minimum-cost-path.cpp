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

// Problem Statement : Given a cost matrix Cost[][] where Cost[i][j] denotes the
//Cost of visiting cell with coordinates (i,j), find a min-cost path to reach a 
// cell (x,y) from cell (0,0) under the condition that you can only travel one step
// right or one step down. (We assume that all costs are positive integers)


// minCost(i, j) = min(minCost(i-1, j), minCost(i, j-1)) + cost[i][j];
int cost[1001][1001];
int dp[1001][1001];

int Kira(int x, int y)
{
	dp[0][0] = cost[0][0];
	for(int i = 1; i < x; i++){
		dp[i][0] = dp[i-1][0] + cost[i][0]; 
	}
	for(int j = 1; j < y; j++){
		dp[0][j] = dp[0][j-1] + cost[0][j];
	}
	for(int i = 1; i < x; i++){
		for(int j = 1; j < y; j++){
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) +  cost[i][j];
		}
	}
	return dp[x-1][y-1];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int x, y;
  cin >> x >> y;
  for(int i = 0; i < x; i++){
  	for(int j = 0; j < y; j++){
  		cin >> cost[i][j];
  	}
  }
  cout << Kira(x, y); 
  return 0;
}