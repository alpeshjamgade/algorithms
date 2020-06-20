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

using namespace std;

const int K = 26;
struct Vertex
{
  int next[K];
  bool leaf = false;

  Vertex(){
    fill(next, next+K, -1);
  }
};


void add_string(string const&s)
{
  int v = 0;
  for(char ch:s){
    int c = ch - 'a';
    if(trie[v].next[c] == -1){
      trie[v].next[c] = trie.size();
      trie.empalce_back();
    }
    v = trie[v].next[c];
  }
  trie[v].leaf = true;
}


vector<Vertex> trie(1);


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  return 0;
}

