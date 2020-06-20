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

string s;
int dp[1001][1001];
// The idea is that we need to find the common subsequence from the same string..
string print_lcs(int l1, int l2)
{
	string res;
	while(l1 > 0 && l2 > 0){
		if(s[l1-1] == s[l2-1] && l1 != l2){
			res += s[l1-1];
			l1--; l2--;
		}
		else if(dp[l1-1][l2] > dp[l1][l2-1]){
			l1--;
		}
		else{
			l2--;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

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
			if(s[i-1] == s[j-1] && i != j){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[l1][l2];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int l = s.length();
  cout << lcs_iter(l, l) << '\n';
  cout << print_lcs(l, l) << '\n';
  return 0;
}