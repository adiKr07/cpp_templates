#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const ll MOD = 1e9+7;
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> matrix_multiply(vector<vector<int>> a,vector<vector<int>> b){
    vector<vector<int>> c(a.size(),vector<int>(b[0].size(),0));
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b[0].size(); j++) {
            for (int k = 0; k < (int)a[0].size(); k++) {
                c[i][j] += (a[i][k]*b[k][j])%MOD;
                c[i][j] = (c[i][j]%MOD);
            }
        }
    }
    return c;
}
 
vector<vector<int>> matrix_exp(vector<vector<int>> a,int p){
    vector<vector<int>> res(a.size(),vector<int> (a.size(),0));
    for (int i = 0; i < (int)res.size(); i++) res[i][i] = 1;
    while(p>0){
        if (p&1) res = matrix_multiply(res,a);
        p = p>>1;
        a = matrix_multiply(a,a);
    }
    return res;
}