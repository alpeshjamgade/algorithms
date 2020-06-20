/*
	Given a set of non-negative integers, and a value sum,
	determine if there is a subset of the given set with sum equal to given sum.
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

int n, S;
int arr[1001];
int dp[1001][1001];

bool solve1(int n, int S)
{
	if(n == 0){ // <-- base condition1, n == 0; solution doesnt exists except when S == 0;
		return (S == 0);      
	}
	if(S == 0){ // <-- base condition2, S == 0. If S == 0, we can always have an empty set
		return true; 
	}
	if(arr[n-1] <= S){
		dp[n][S] = (solve1(n-1, S) || solve1(n-1, S-arr[n-1]));
	}
	else{
		dp[n][S] = solve1(n-1, S);
	}
	return dp[n][S];
}

bool solve2(int n, int S)
{
	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}
	for(int i = 1; i <= S; i++){
		dp[0][i] = false; 
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= S; j++){
			if(arr[i-1] <= ){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
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
  cout << solve1(n, S); 
  return 0;
}