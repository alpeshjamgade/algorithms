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




void solve()
{
  int n, W;
  cin >> W >> n;
  vector<vector<int>> p(n+1, vector<int>(W+1, 0)), s(n+1, vector<int>(W+1, 0));
  int val[n], wt[n];
  for(int i = 0; i < n; i++){
    cin >> wt[i];
  }
  for(int i = 0 ; i < n; i++){
    cin >> val[i];
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= W; j++){
      if(wt[i-1] > j){
        p[i][j] = p[i-1][j];
      }else{
        int tmp = p[i-1][j-wt[i-1]]+val[i-1];
        if(tmp > p[i-1][j]){
          p[i][j] = tmp;
          s[i][j] = 1;
        }
        else{
          p[i][j] = p[i-1][j];
        }
      }
    }
  }
  cout << p[n][W];
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tt = 1;
  //cin >> tt;
  while(tt--){
    solve();
    /*cout << p[n][W] << '\n';
    for(int i = n; i>= 1; i--){
      if(s[i][j] == 1){
        cout << i << ' ';
        j -= wt[i-1];
      }
    }*/
  }
  return 0;
}

