#include <bits/stdc++.h>
using namespace std;
const int MAXN=30;
int n, K;
int c[30][30];
int c_min=1000;
bool visited[MAXN];
int load;
int f, f_min;
int X[MAXN];
void input(){
    cin >> n >> K;
    for(int i =0; i <=2*n; i++){
        for(int j=0; j <=2*n; j++){
            cin >> c[i][j];
            if(c[i][j]< c_min && c[i][j] !=0)
                c_min = c[i][j];
    }
    }
}
bool check(int v, int k){
    if(visited[v]) return false;
    if(v > n){
        if(!visited[v-n]) return false;

    }
    else {
        if (load +1 >K) return false;
    }
    return true;
}
void updatebest(){
    if (f+c[X[2*n]][0] < f_min){
        f_min = f+c[X[2*n]][0];
    }
}
void TRY(int k){
    for(int v=1; v<= 2*n; v++){
        if(check(v,k)){
            X[k]=v;
            f = f+c[X[k-1]][X[k]];
            visited[v]=true;
            if(v<=n) load++;
            else load--;
            if(k==2*n) updatebest();
            else{
                if(f+c_min*(2*n+1-k) < f_min) {
                    TRY(k+1);
                } 
            }
            if(v <= n) load--; 
            else load++;
            f= f-c[X[k-1]][X[k]];
            visited[v]=false;
        }

    }
}
void solve(){
    f = 0; f_min = 100000;
    load =0;
    for (int v = 1 ; v<= 2*n ; v++)
        visited[v] = false;
    TRY(1);
    cout << f_min;
}
int main(){
    input();
    cout << c[6][0] << endl;
    solve();
    return true;
}
