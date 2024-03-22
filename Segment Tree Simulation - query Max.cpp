#include<bits/stdc++.h>
using namespace std;
struct query {
    string s;
    int l;
    int r;
};
const int MaxN= 10000;
int n;
int m;
int l, r;
int a[MaxN], st[MaxN][MaxN];
vector<query> Q;
void input(){
    cin >> n;
    for (int i = 1 ; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;

    for(int i = 0; i < m; i++){
       query q;
        cin >> q.s >> q.l >> q.r;
        Q.push_back(q);
    }
}


void preprocess() {
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int queryMin(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}
int main(){
    input();
    preprocess();
    for(int i = 0; i < m; i++){
        if(Q[i].s.compare("update")==0){
            a[Q[i].l] = Q[i].r;
            preprocess();
        }
        if(Q[i].s.compare("get-max")==0){

           cout << queryMin(Q[i].l,Q[i].r) << endl;
        }
    }

    return 0;
}
