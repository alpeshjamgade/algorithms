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

// Find the length of longest subsequence of one string,
// which is the substring of another stirng;

string s1, s2;
int dp[1001][1001];

int lcs_iter(int l1, int l2)
{
	for(int i = 0; i <= l1; i++){
		dp[i][0] = 0;
	}
	for(int j = 0; j <= l2; j++){
		dp[0][j] = 0;
	}

	for(int i = 1; i <= l1; i++){
		for(int j = 1; j <= l2; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	int res = -1;
	for(int i = 0; i <= l2; i++){
		res = max(res, dp[i][l1]);
	}
	return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s1 >> s2;
  int l1 = s1.length(), l2 = s2.length();
  cout << lcs_iter(l1, l2) << '\n';
  return 0;
}