#include <bits/stdc++.h>
using namespace std;

// 2. KMP Algorithm
// time complexity : O(n+m);
// space complexity : O(m)
vector<int> compute_lps(string pat)
{

    vector<int> lps(pat.length());
    int index = 0;
    for(int i =1; i < (int)pat.length();){
        if(pat[i] == pat[index]){
            lps[i] = index+1;
            i++;
            index++;
        }
        else{
            if(index != 0){
                index = lps[index-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp_search(string text, string pat)
{
    vector<int> lps = compute_lps(pat), res;
    int i = 0;
    int j = 0;
    while(i < (int)text.length() ){
        if(text[i] == pat[j]){
            i++; j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j == (int)pat.length()){
            res.emplace_back(i-j);
        }
    }
    return res;
}



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  
  string s, s1;
  s = "AlpeshJamgade";
  s1 = "Jam";
  auto res = kmp_search(s, s1);
  for(auto it:res){
    cout << it << ' ';
  }
  //cout << res.size() << '\n';
  return 0;
}
