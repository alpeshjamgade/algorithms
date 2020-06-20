#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b

using namespace std;

#ifdef LOCAL_DEFINE
    freeopen("input.txt", "rt", stdin);
#endif
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << " s.\n";
#endif

int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> v(8);
	ll total = 0;
	cout << v.size();
	for(int i = 0; i < 8; i++){
		cin >> v[i];
		total += v[i];
		cout << v[i] << ' ';
	}
	//cout << '\n';
	int p; cin >> p;
	for(int i = 0; i < p; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		//cout << x << y;
		//cout << v[x] << v[y];
		//total -= min(v[x], v[y]);
	}
	cout << total << '\n';
	return 0;
}