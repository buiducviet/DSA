#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
#define MaxN 10002
int m, n;
int A[MaxN][MaxN];
queue<PII> q;
bool mark[MaxN][MaxN];
int d[MaxN][MaxN];

PII s, temp;
void input(){
    cin >> n >> m;
    cin >> s.first >> s.second;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> A[i][j];
            mark[i][j]= false;
        }
    }

    for(int i = 1; i<=m; i++){
        A[0][i] = -1;
        A[n+1][i] = -1;
    }
    for(int i = 1; i<=n; i++){
        A[i][0] = -1;
        A[i][m+1] = -1;
    }
    


}
void output(){
    for(int i = 0 ; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
void bfs(PII t){
    q.push(t);
    d[t.first][t.second] = 0;
    mark[t.first][t.second]= true;
    while(!q.empty()){
            PII p = q.front();
            q.pop();
            int px= p.first;
            int py = p.second;
            if(A[px+1][py]==-1 || A[px][py+1] == -1 ||A[px][py-1] == -1 || A[px-1][py] == -1 ){
                cout << d[px][py] + 1;
                break;
            }
            if(A[px+1][py]==0 && mark[px+1][py]==false){
                temp = {px+1, py};
                q.push(temp);
                d[px+1][py] = d[px][py]+1;
                
                mark[px+1][py] = true;
            }
            if(A[px][py+1]==0 && mark[px][py+1]==false){
                temp = {px, py+1};
                q.push(temp);
                d[px][py+1] = d[px][py]+1;
               
                mark[px][py+1] = true;
            }
            if(A[px-1][py]==0 && mark[px-1][py]==false){
                temp = {px-1, py};
                q.push(temp);
                d[px-1][py] = d[px][py]+1;
                
                mark[px-1][py] = true;
            }
            if(A[px][py-1]==0 && mark[px][py-1]==false){
                temp = {px, py-1};
                q.push(temp);
                d[px][py-1] = d[px][py]+1;
               
                mark[px][py-1] = true;
            }
           
    }
};
int main(){
    freopen("input.txt", "r", stdin);
    input();
    bfs(s);
    return 0;
}