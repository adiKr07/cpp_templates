#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class FenWickTree{
private:
	int n;
	vector <int> bit;
public:
	FenWickTree(vector <int> &a){
		n = a.size();
	    bit = a;

	    for(int i = 0; i < n; i++){
	        int j = i | (i + 1);
	        if(j < n)
	            bit[j] += bit[i];
	    }
	}
	void add(int x,int val){
		for(int i = x;i < n;i = (i|(i+1))){
			bit[i]+=val;
		}
	}
	int sum(int x,int val){
		int sum = 0;
		for(int i = x;i >= 0;i = (i&(i+1))-1){
			sum += bit[i];
		}
		return sum;
	}
	int kth(long long k){ // find_by_order(k) for pbds kind of  structure where the bits store the frequencies
        int pos=-1;

        int pw=1;
        while((pw<<1)<=n) pw<<=1;

        for(int step=pw;step;step>>=1){
            int nxt=pos+step;
            if(nxt<n && bit[nxt]<k){
                k-=bit[nxt];
                pos=nxt;
            }
        }
        return pos+1;
    }
};

/*   /\_/\
*   (= ._.)
*   / >  \>
*/