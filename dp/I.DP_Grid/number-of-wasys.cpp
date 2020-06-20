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

// Problem Statement : Given a 2-D matrix with M rows and N columns,
// find the number of ways to reach cell with coordinates (i,j) from
// starting cell (0,0) under the condition that you can only travel one step right or one step down.

int arr[1001][1001];
int dp[1001][1001];

int Kira(int x, int y)
{
	dp[0][0] = 1;
	for(int i= 1; i < x; i++){
		dp[i][0] = 1;
	}
	for(int j = 1; j < y; j++){
		dp[0][j] = 1;
	}
	for(int i = 1; i < x; i++){
		for(int j = 1; j< y; j++){
			dp[i][j] = dp[i-1][j] + d[i][j-1];
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
  cout << Kira(x, y) << '\n';
  return 0;
}