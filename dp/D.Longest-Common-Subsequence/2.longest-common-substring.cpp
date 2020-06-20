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

int lcst_recur(int l1, int l2, int count)
{
	if(l1 == 0 || l2 == 0){
		return count;
	}
	if(s1[l1-1] == s2[l2-1]){
		count = lcst_recur(l1-1, l2-1, count + 1);
	}
	count = max(count, max(lcst_recur(l1, l2-1, 0), lcst_recur(l1-1, l2, 0)));
	return count;
}

string print_lcst()
{
	int tmp = 0;
	int l1 = -1, l2 = -1;
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++)
			if(tmp < dp[i][j]){
				tmp = dp[i][j];
				l1 = i;
				l2 = j;
			}
	}
	string res;
	while(dp[l1][l2]){
		res += s1[l1-1];
		l1--;
		l2--;
	}
	reverse(res.begin(), res.end());
	return res;
}

int lcst_iter(int l1, int l2)
{
	int res = 0;
	int index1 = -1, index2 = -1;
	for(int i = 1; i <= l1; i++){
		for(int j = 1; j <= l2; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				res = max(res, dp[i][j]);
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	return res;
}



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s1 >> s2;
  //memset(dp, -1, sizeof(dp));
  int l1 = s1.length(), l2 = s2.length();
  cout << lcst_iter(l1, l2) << '\n';
  //out << print_lcs(l1, l2) << '\n';
  return 0;
}