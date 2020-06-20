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

int lps_iter(int l)
{
	for(int i = 0; i < l; i++){
		dp[i][i] = 1;
	}
	for(int len = 2; i <= l; len++){
		for(int i = 0; j <= l - len; j++){
			int j = i + len - 1;
			if(s[i] = s[j]){
				if(len == 2){
					dp[i][j] = 2;
				}
				else{
					dp[i][j] = dp[i+1][j-1] + 2; 
				}
			}
			else{
				dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return dp[0][l-1];
}

int lps_recur(int l1, int l2)
{

	return 0;
}

string print_lps()
{
	
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s1;
  cout << lps_iter(l1) << '\n';
  return 0;
}