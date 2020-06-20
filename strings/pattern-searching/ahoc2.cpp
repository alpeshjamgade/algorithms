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

struct trie_node
{
  map<char, trie_node*> child;
  trie_node*  suffix_link;
  trie_node* output_link;
  ll pattern_ind;
};

typedef trie_node node;

node *add_node()
{
  node *tmp = new node();
  tmp->suffix_link = nullptr;
  tmp->output_link = nullptr;
  tmp->pattern_ind = -1;

  return tmp;
}

void build_trie(node* root, vector<string> &patterns)
{
  for(int i = 0 ; i < patterns.size(); i++){
    node *cur = root;
    for(auto c: patterns[i]){
      if(cur->child.count(c)){
        cur = cur->child[c];
      }
      else{
        node* new_child = add_node();
        cur->child.insert({c, new_child});
        cur = new_child;
      }
    }
    cur->pattern_ind = i;
  }
}

void build_suffix_and_output_links(node *root)
{
  root->suffix_link = root;
  queue<node*> qu;
  for(auto&it: root->child){
    qu.push(it.second);
    it.second->suffix_link = root;
  }

  while(qu.size()){
    node* cur_state = qu.front();
    qu.pop();

    for(auto &it: cur_state->child){
      char c = it.first;
      node* tmp = cur_state->suffix_link;

      while(tmp->child.count(c) == 0 && tmp != root){
        tmp = tmp->suffix_link;
      }
      if(tmp->child.count(c)){
        it.second->suffix_link = tmp->child[c];
      }
      else{
        it.second->suffix_link = root;
      }

      qu.push(it.second);
    }

    if(cur_state->suffix_link->pattern_ind >= 0){
      cur_state->output_link = cur_state->suffix_link;
    }
    else{
      cur_state->output_link = cur_state->suffix_link->output_link;
    }
  }
}

void search_pattern(node* root, string &text, auto& indices)
{
  node *parent = root;

  for(int i = 0; i < text.length(); i++){
    char c = text[i];
    if(parent->child.count(c)){
      parent = parent->child[c];

      if(parent->pattern_ind >= 0){
        indices[parent->pattern_ind].push_back(i);
      }

      node* tmp = parent->output_link;
      while(tmp != nullptr){
        indices[tmp->pattern_ind].push_back(i);
        tmp = tmp->output_link;
      }
    }
    else{
      while(parent != root && parent->child.count(c) == 0){
        parent = parent->suffix_link;
      }
      if(parent->child.count(c)){
        i--;
      }
    }
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  int n, q;
  cin >> n >> q;
  string text; cin >> text;
  vector<string> patterns(q);
  for(int i = 0; i < q; i++){
    cin >> patterns[i];
  }

  node* root = add_node();
  build_trie(root, patterns);
  build_suffix_and_output_links(root);
  vector<vector<int>> indices(q, vector<int>());
  search_pattern(root, text, indices);
  for(int i = 0; i < q; i++){
    cout << indices[i].size() << '\n';
  }
  return 0;
}

