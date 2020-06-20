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

string s1, s2;
int dp[1001][1001];

string print_scs(int l1, int l2)
{
	string res;
	int index = dp[l1][l2];
	while(l1 > 0 && l2 > 0){
		if(s1[l1-1] == s2[l2-1]){
			res += s1[l1-1];
			l1--; l2--;
			index--;
		}
		else if(dp[l1-1][l2] > dp[l1][l2-1]){
			res += s2[l2-1];
			l2--;
			index--;
		}
		else{
			res += s1[l1-1];
			l1--;
			index--;
		}
	}
	while(l1 > 0){
		res += s1[l1-1];
		l1--;
		index--;
	}
	while(l2 > 0){
		res += s2[l2-1];
		l2--;
		index--;
	}
	
	reverse(res.begin(), res.end());
	return res;
}

int scs_iter(int l1, int l2)
{
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			if(!i){
				dp[i][j] = j;
			}
			else if(!j){
				dp[i][j] = i;
			}
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[l1][l2];
}


int scs_recur(int l1, int l2)
{
	if(l1 == 0){
		return l2;
	}
	else if(l2 == 0){
		return l1;
	}
	if(dp[l1][l2] != -1){
		return dp[l1][l2];
	}
	else if(s1[l1-1] == s2[l2-1]){
		dp[l1][l2] = 1 + scs_recur(l1-1, l2-1);
	}
	else{
		dp[l1][l2] = 1 + min(scs_recur(l1-1, l2), scs_recur(l1, l2-1));
	}
	return dp[l1][l2];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s1 >> s2;
  int l1 = s1.length(), l2 = s2.length();
  cout << scs_iter(l1, l2) << '\n';
  memset(dp, -1, sizeof(dp));
  cout << scs_recur(l1, l2) << '\n';

  cout << print_scs(l1, l2) << '\n';
  return 0;
}