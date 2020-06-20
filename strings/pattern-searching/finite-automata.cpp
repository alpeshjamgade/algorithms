#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b)

using namespace std;



vector<vector<int>> computeTF(string pattern, int NFC = 256)
{
	int lps = 0, l = pattern.length();
	vector<vector<int>> TF(l+1, vector<int> (NFC, 0));
  TF[0][pattern[0]] = 1;
	for(int i = 1; i <= l; i++){
		for(int j = 0; j < NFC; j++){
			TF[i][j] = TF[lps][j];
		}
		TF[i][pattern[i]] = i+1;
		if(i < l){
			lps = TF[lps][pattern[i]];
		}
	}
	return TF;
}


vector<int> automata_search(string text, string pattern)
{
  int l1 = text.length(), l2 = pattern.length();
  vector<int> res;
  vector<vector<int>> TF = computeTF(pattern);
  int j = 0;
  for(int i = 0; i < l1; i++){
    j = TF[j][text[i]];
    if(j == l2){
      res.emplace_back(i-l2+1);
    }
  }
  return res;
}

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  //int n, q; cin >> n >> q;
  string text, pattern; cin  >> text >> pattern;
  //while(q--){
  //cin >> pattern;
  //auto res = automata_search(text, pattern);
  //cout << res.size() << '\n';
  //}
  auto res = automata_search(text, pattern);
  //cout << res.size() << '\n';
  for(auto it: res){
    cout << it << '\n';
  }
	return 0;
}
