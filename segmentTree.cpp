#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class SegTree{
private:
	int size;
	vector <ll> t;
	vector<ll> lazy;
public:
	SegTree(int n){
		this->size = n;
		t.assign(4*n,0);
		lazy.assign(4*n,0);
	}

	void push1(int l,int r,int node){
		if(lazy[node] == 0)return;
		int m = (l + r)/2;
		int si1 = m - l + 1;
		int si2 = r - m;
		t[2*node] += lazy[node]*si1;
	    lazy[2*node]  += lazy[node];  
	    t[2*node+1] += lazy[node]*si2;
        lazy[2*node+1] += lazy[node];
	    lazy[node] = 0;
	}
	void create(vector <int> &num,int l,int r,int v){
		if(l == r){
			t[v] = num[l];
		}else{
			int m = (l + r)/2;
			create(num,l,m,2*v);
			create(num,m+1,r,2*v+1);
			t[v] = t[2*v] + t[2*v+1];
		}
	}

	void up1(int v,int l,int r,int tl,int tr,ll x){
		if(l > r)return;
		if(tl >= l && tr <= r){
			t[v] += 1LL*(tr - tl + 1)*x;
		    lazy[v] += x;          
			return;
		}
		push1(tl,tr,v);
		int m = (tl + tr)/2;
		up1(2*v,l,min(m,r),tl,m,x);
		up1(2*v+1,max(l,m+1),r,m+1,tr,x);
		t[v] = t[2*v] + t[2*v+1];
	}

	long long su(int v,int l,int r,int tl,int tr){
		if(l > r)return 0;
		if(l <= tl && tr <= r){
			return t[v];
		}
		push1(tl,tr,v);
		int m = (tl + tr)/2;
		return su(2*v,l,min(m,r),tl,m) + su(2*v+1,max(l,m+1),r,m+1,tr);
	}
};

/*   /\_/\
*   (= ._.)
*   / >  \>
*/