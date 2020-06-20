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


const int MAXN = 1e9+7;
const int MAXCHAR = 26;

struct Vertex {
  int next[MAXCHAR], go[MAXCHAR];
  int leaf = -1;
  int p = -1;
  char pch;
  int link = -1, leaflink = -1;

  Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
  }
};

vector<Vertex> trie(1);
 
void add_string(string const &s, int idx) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back(v, ch);
    }
    v = trie[v].next[c];
  }
  trie[v].leaf = idx;
}

int go(int v, char ch);
 
int get_link(int v) {
  if (trie[v].link == -1) {
    if (v == 0 || trie[v].p == 0)
      trie[v].link = 0;
    else
      trie[v].link = go(get_link(trie[v].p), trie[v].pch);
    get_link(trie[v].link); // 
    trie[v].leaflink = (trie[trie[v].link].leaf != -1) ? trie[v].link : trie[trie[v].link].leaflink;
  }
  return trie[v].link;
}
 
int go(int v, char ch) {
  int c = ch - 'a';
  if (trie[v].go[c] == -1) {
    if (trie[v].next[c] != -1)
      trie[v].go[c] = trie[v].next[c];
    else
      trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
  }
  return trie[v].go[c];
}



int K[MAXN];
string M[MAXN];
vector<int> results[MAXN];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for(int i = 0; i < n; i++){
    cin >> K[i];
    cin >> M[i];
    add_string(M[i], i);
  }

  for(int i = 1; i < trie.size(); i++){
    get_link(i);
  }
  int v = 0;
  for(int i = 0; i < s.size(); i++){
    v = go(v, s[i]);
    int cur = v;
    while(cur != -1){
      if(trie[cur].leaf != -1){
        results[trie[cur].leaf].push_back(i);
      }
      cur = trie[cur].leaflink;
    }
  }
  for(int i = 0; i < n; i++){
    int minlength = 1 << 30;
    for(int j = K[i]; j <= results[i].size(); j++){
      minlength = min(minlength, results[i][j-1] - results[i][j-K[i]]);
    }
    if(minlength == 1 << 30){
      cout << -1 << endl;
    }
    else{
      cout << minlength + M[i].size() << endl;
    }
  }
  return 0;
}

