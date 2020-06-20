#include <bits/stdc++.h>
#define prime 101

using namespace std;

long createHash(string pat, int end)
{
	long hash = 0;
	for(int i = 0; i <= end; i++){
		hash += pat[i]*pow(prime, i);
	}
	return hash;
}


long recalculateHash(string abc, int oldIndex, int newIndex, long oldHash, int patLen){
	long newHash = oldHash - abc[oldIndex];
	newHash = newHash/prime;
	newHash += abc[newIndex]*pow(prime, patLen-1);
	return newHash;
}



bool checkEqual(string str1, int start1, int end1, string str2, int start2, int end2){
	if(end1-start1 != end2 - start2){
		return false;
	}
	while(start1 <= end1 && start2 <= end2){
		if(str1[start1] != str2[start2]){
			return false;
		}
		start1++;
		start2++;
	}
	return true;
}



vector<int> rk_search(string text, string pat)
{
	int m = pat.length();
	int n = text.length();
	long patHash = createHash(pat, m-1);
	long textHash = createHash(text,m-1);

	vector<int> res;
	for(int i =1; i <= n-m+1; i++){
		if(patHash == textHash && checkEqual(text, i-1, i+m-2, pat, 0, m-1)){
			res.emplace_back(i-1);
		}
		if(i < n-m+1){
			textHash = recalculateHash(text, i-1, i+m-1, textHash, m);			
		}
	}
	return res;
}


int main()
{
  string text, pattern;
  cin >> text >> pattern;
  auto res = rk_search(text, pattern);
  for(auto it : res){
    cout <<it <<' ';
  }
  cout << '\n';
}
