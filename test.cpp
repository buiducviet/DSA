//C++
#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;
int n, K, Q;
int d[MAXN];
int c[MAXN][MAXN];
int x[MAXN];
bool visited[MAXN];
int load[MAXN];
int y[MAXN];
int f, f_min;
int segments, nbR;
void input(){
    cin >> n >> K >> Q;
    for(int i = 1; i <=n; i++){
        cin >> d[i];
    }
    for(int i = 0; i <=n ; i++){
        for(int j=0; j<=n ; j++){
            cin >> c[i][j];
        }
    }
}
bool checkX(int v, int k){
    if (v > 0 && visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;
    return true;
}
void updatebest(){
    if (f_min < f) f_min = f_min;
    else f_min = f;
}
void TRY_X(int s, int k)
{
    if(s == 0){
        if (k < K) 
            TRY_X(y[k+1],k+1);
        return;
    }
    for (int v = 0 ; v<= n; v++) do {
        if(checkX(v,k)){
            x[s] = v; visited[v] = true; 
            f = f + c[s][v];
            load[k] = load[k] + d[v]; segments = segments + 1;
            if(v > 0 ) { 
                if (f + (n + nbR - segments)*Cmin < f_min)      
                    TRY_X(v,k);
            }
            else{
                if (k == K)  {
                    if (segments = n + nbR) updatebest();
                }else{
                    if (f + (n + nbR - segments)*Cmin < f_min) TRY_X(y[k+1],k+1);
                }
            }
            visited[v] = false;
             f = f - c[s][v];
            load[k] = load[k]  - d[v]; 
            segments = segments - 1;
        }
    }
}

bool checkY(int v,int  k){
    if(v == 0 ) return true;
    if (load[k] + d[v] > Q) 
        return false;
    if (visited[v]) 
        return false;
    return true;
}
void TRY_Y(int k){ // thử giá trị cho y[k]
    int s = 0;
    if (y[k-1] > 0) 
        s = y[k-1] + 1;
    for (int v = s ; v<= n; v++)  {
        if (checkY(v,k)){
            y[k] = v;
            if( v > 0 ) segments = segments + 1;
            visited[v] = true; 
            f = f + c[0][v]; 
            load[k] = load[k] + d[v];
            if (k < K) TRY_Y(k+1);
            else { nbR = segments; 
                    TRY_X(y[1],1); 
                }
            load[k] = load[k] - d[v]; 
            visited[v] = false; f = f - c[0][v];
            if (v > 0) segments = segments - 1;
        }
    }
}
void solve(){
    f = 0; f_min = 100000; y[0] = 0;
    for (int v = 1 ; v<= n ; v++)
        visited[v] = false;
    TRY_Y(1);
    cout << f_min;
}
int main()
{
    input();
    solve();
    return 0;
}
