#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void LIS() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)cin>>i;
    vector<int> d(n+1,1e9);
	d[0] = -1e9;
	for(int i = 0;i<n;i++){
		int l = upper_bound(all(d),v[i]) - d.begin();
		if(d[l-1] < v[i] && v[i] < d[l])d[l] = v[i];
	}
	int ans = 1;
	for(int i = 1;i<=n;i++){
		if(d[i] < 1e9)ans = i;
	}
	cout<<ans<<endl;
}

