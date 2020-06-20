//using dynamic_programming


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




int lcs_iter(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	vector<vector<int>> lcs(l1+1, vector<int> (l2+1, 0));
	for(int i = 1; i <= l1; i++){
		for(int j = 1; j <= l2; j++){
			if(s1[i-1] == s2[j-1]){
				lcs[i][j] = lcs[i-1][j-1]+1;
			}
			else{
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
		}
	}
	return lcs[l1][l2];
	/*
	char ans[index+1];
	ans[index] = '\0';
	while( l1 > 0 && l2 > 0){
		if(s1[l1-1] == s2[l2-1){
			ans[index-1] = s1[l1-1];
			l1--; l2--; index--;
		}
		else if(lcs[l1-1[l2] > lcs[l1][l2-1]){
			l1--;
		}
		else{
			l2--;		
		}	
	}
	return ans;
	*/
}




int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1 = "AlpeshJamgade";
	string s2 = "Alpeh";
	cout << lcs_iter(s1, s2);
	return 0;
}