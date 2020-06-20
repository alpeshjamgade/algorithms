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
bool dp[1001][1001];

pair<int, string> lpst(int l)
{
	memset(dp, 0, sizeof dp);
	int maxLength = 1, start = 0;

	for(int i = 0; i < l; i++){
		dp[i][i] = true;
	}
	for(int i= 0; i < l-1; i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = true;
			start = i;
			maxLength = 2;
		}
	}
	for(int len = 3; len <= l; len++){
		for(int i = 0; i <= l-len; i++){
			int j = i+len-1;
			if(dp[i+1][j-1] && s[i] == s[j]){
				dp[i][j] = true;
				if(len > maxLength){
					start = i;
					maxLength = len;
				}
			}
		}
	}
	
	string res = "";
	for(int i = start; i <= start+maxLength-1; i++){
		res += s[i];
	}
	return mp(maxLength, res);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  auto res = lpst(s.length());
  cout << res.first << " " << res.second << '\n';
  return 0;
}