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
#define prime 101

using namespace std;


vector<int> naive_search(string text, string pattern)
{
  int l1 = text.length();
  int l2 = pattern.length();
  vector<int> res;
  for(int i = 0; i <= l1-l2+1; i++){
    int j;
    for(j = 0; j < l2; j++){
      if(pattern[j] != text[i+j]){
        break;
      }
    }
    if(j == l2){
      res.emplace_back(i);
    }
  }
  return res;
}


vector<int> compute_lps(string pattern, int l)
{
  vector<int> lps(l);
  int j = 0;
  for(int i = 1; i < l; i++){
    if(pattern[i] == pattern[j]){
      lps[i] = j+1;
      i++;
      j++;
    }
    else{
      if(j != 0){
        j = lps[j-1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

vector<int> kmp_search(string text, string pattern)
{
  int l1 = text.length();
  int l2 = pattern.length();
  vector<int> res, lps = compute_lps(pattern, l2);
  
  int i = 0;
  int j = 0;
  while(i < l1){
    if(pattern[j] == text[i]){
      i++;
      j++;
    }
    else{
      if(j != 0){
        j = lps[j-1];
      }
      else{
        i++;
      }
    }
    if(j == l2){
      res.emplace_back(i-j);
    }
  }
  return res;
}


vector<int> computez(string s, int l)
{
  vector<int> z(l);
  z[0] = 1;
  int left = 0, right = 0;
  for(int k = 1; k < l; k++){
    if(k > right){
      left = right = k;
      while(right < l && s[right-left] == s[right]){
        right++;
      }
      z[k] = right-left;
      right--;
    }
    else{
      int k1 = k - left;
      if(z[k1] < right-k+1){
        z[k] = z[k1];
      }
      else{
        left= k;
        while(right < l && s[right-left] == s[right]){
          right++;
        }
        z[k] = right-left;
        right--;
      }
    }
  }
  return z;
}
vector<int> z_search(string text, string pattern)
{
  string s = pattern + '$' + text;
  int l = s.length();
  vector<int> res, z = computez(s, l);
  for(int i = 0; i < l; i++){
    if(z[i] == pattern.length()){
      res.emplace_back(i-pattern.length()-1);
    }
  }
  return res;
}


ll calculateHash(string abc, int end)
{
  ll newHash = 0;
  for(int i = 0; i<= end; i++){
    newHash += abc[i]*pow(prime, i);
  }
  return newHash;
}

ll recalculateHash(string abc, int oldIndex, int newIndex, ll oldHash, int patlen)
{
  ll newHash = oldHash - abc[oldIndex];
  newHash /= prime;
  newHash += abc[newIndex]*pow(prime, patlen-1);
  return newHash;
}

bool checkEqual(string s1, int st1, int ed1, string s2, int st2, int ed2)
{
  if(st1-ed1 != st2-ed2){
    return false;
  }
  while(st1 <= ed1){
    if(s1[st1] != s2[st2]){
      return false;
    }
    st1++;
    st2++;
  }
  return true;
}

vector<int> rk_search(string text, string pattern)
{
  int l1 = text.length();
  int l2 = pattern.length();
  ll textHash = calculateHash(text, l2-1);
  ll patternHash = calculateHash(pattern, l2-1);
  vector<int> res;
  for(int i = 1; i <= l1-l2+1; i++){
    if(patternHash == textHash && checkEqual(text, i-1, i+l2-2, pattern, 0, l2-1)){
        res.emplace_back(i-1);
    }
    textHash = recalculateHash(text, i-1, i-1+l2, textHash, l2);
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  string text = "AlpeshJamgadeJam";
  string pattern = "Jam";
  auto res = rk_search(text, pattern);
  for(auto it : res){
    cout << it << ' ';
  }
  return 0;
}
