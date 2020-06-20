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



int lps_iter(string abc)
{
	vector<vector<int>> v(abc.length(), vector<int> (abc.length(), 1));
	for(int i =0; i < abc.length(); i++){
		for(int j = 0; j < abc.length()-i+1; j++){
			int k = i+j-1;
			if(i == 2 && abc[i] == abc[k]){
				v[i][k] = 2;
			}else if(abc[i] == abc[k]){
				v[i][k] = v[i+1][k-1]+2;
			}else{
				v[i][j] = max(v[i+1][k], v[i][k-1]);
			}
		}
	}
	return v[0][abc.length()-1];
}


int lps_recur(string abc, int start, int len)
{
	if(len == 1){
		return 1;
	}
	if(len == 0){
		return 0;
	}
	if(abc[start] == abc[start+len+1]){
		return 2 = lps_recur(abc, start+1, len-2);
	}else{
		return max(lps_recur(abc, start+1, len-1), lps_recur(abc, start+1, len-1));
	}
}








int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	return 0;
}