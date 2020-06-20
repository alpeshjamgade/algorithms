#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b

using namespace std;

// O(n+m)




vector<int> computeZ(string s)
{
  int n = s.length();
  vector<int> z(n);
  z[0] = 0;
  for(int i = 1, l = 0, r = 0; i < n; ++i){
    if(i <= r){
      z[i] = min(r-i+1, z[i-l]);
    }
    while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
      ++z[i];
    }
    if(i+z[i]-1 > r){
      l = i, r = i+z[i]-1;
    }
  }
  return z;
}
vector<int> compute_z(string pattern)
{
	vector<int> z(pattern.length());
	int left = 0;
	int right = 0;
  z[0] = 0;
	for(int k = 1; k < pattern.length(); k++){
		if(k > right){
			left = k;
			right = k;
			while(right < pattern.length() && pattern[right] == pattern[right-left]){
				right++;
			}
			z[k] = right - left;
			right--;
		}
		else{
			int k1 = k -left;
			if(z[k1] < right-k+1){
				z[k] = z[k1];
			}
			else{
				left = k;
				while(right < pattern.length() && pattern[right] == pattern[right-left]){
					right++;
				}
				z[k] = right-left;
				right--;
			}
		}
	}
	return z;
}


vector<int> zsearch(string text, string pattern)
{
	string zstr(text.length()+pattern.length()+1, '0');
	int i = 0;
	for(char ch: pattern){
		zstr[i] = ch;
		i++;
	}
	zstr[i] = '$'; i++;
	for(char ch:text){
		zstr[i] = ch;
		i++;
	}
	vector<int> rs;
	vector<int> z = compute_z(zstr);
	for(int i = 0; i < z.size(); i++){
		if(z[i] == pattern.length()){
			rs.emplace_back(i-pattern.length()-1);
		}
	}
	return rs;
}
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string text = "AlpeshJamgadeAl";
	string pattern = "Al";
	auto ans = computeZ("abacaba");
  auto ans1 = compute_z("abacaba");
	for(auto it : ans){
		cout << it << ' ';
	}
  cout << '\n';
  for(auto it :ans1){
    cout << it << ' ';
  }
  cout << '\n';
	return 0;
}
