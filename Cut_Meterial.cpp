#include <bits/stdc++.h>
using namespace std;
const int MAXN= 100;
int H, W;// height and width of the rectangle
int h[MAXN], w[MAXN];
int mark[MAXN][MAXN];
bool canCut = false;
int n;
void input(){
    cin >> H >> W;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> h[i] >> w[i];
    }
}
void mark_down(int vx, int vy,int wk,int hk, bool mark_value){
    for(int i = vx; i <= vx + wk- 1; i++)
        for(int j = vy; j <= vy + hk - 1; j++)
            mark[i][j] = mark_value;
}
bool check(int vx,int vy,int wk,int hk){
    if(vx + wk > W) return false;
    if(vy + hk > H) return false;
    for(int i = vx; i <= vx + wk - 1; i++)
        for(int j = vy; j <= vy + hk - 1; j++)
            if(mark[i][j]) return false;
    return true;
}
void Try(int k){

        for(int vx = 0 ; vx <= W-w[k]; vx++)  {
            for(int vy = 0; vy <= H-h[k]; vy++)   {
                if(check(vx,vy,h[k],w[k]))  {
                    mark_down(vx,vy,h[k],w[k], true); // do mark
                    if (k == n) canCut=true; else Try(k+1);
                    mark_down(vx,vy,h[k],w[k], false); // undo mark
                }
                if(check(vx,vy,w[k],h[k]))  {
                    mark_down(vx,vy,w[k],h[k], true); // do mark
                    if (k == n) canCut=true; else Try(k+1);
                    mark_down(vx,vy,w[k],h[k], false); // undo mark
                }
            }
        }

}
int main(){
     input();
     Try(1);
     if(canCut) cout << 1 ;
     else cout << 0;
     return 0;

}
