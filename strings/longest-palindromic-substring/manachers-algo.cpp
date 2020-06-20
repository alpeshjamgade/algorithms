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
int d1[1001];
int d2[1001];

int manacher(int n)
{
	int res = 0;
	for(int i = 0; l= 0, r = -1; i < n; i++){
		int k = (i>r)?1:min(d1[l+r-i], r-i+1);
		while(0 <= i-k && i+k < n && s[ii-k] == s[i+k]){
			k++;
		}
		d1[i] = k--;
		res = max()
		if(i+k > r){
			l = i-r;
			r = i+k;
		}
	}
	for(int i = 0; l = 0, r = -1; i < n; i++){
		int k = (i>r)?0:min(d2[l+r-i+1], r-i+1);
		while(0 <= i - k -1 && i_k < n && s[i-k-1] == s[i+k]){
			k++:
		}
		d2[i] = k--;
		if(i+k>r){
			l = i-k-1;
			r = i+k;
		}
	}

}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int l = s.length();
  cout <<  manacher(l) << '\n;
  return 0;
}