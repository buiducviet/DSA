#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int numbers[MAX][MAX], S[MAX][MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    //int numbers[n][m], S[n][m] ;
    int Q;
    int r1, c1, r2, c2;
    vector< int > res;
    for (int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m ; j++){
            cin >> numbers[i][j] ;
        }
        
    }
    for(int i = 0; i <= n; i++) {
        S[i][0] = 0;
    }
    for(int j = 0; j <= m; j++) {
        S[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ; j++){
           S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + numbers[i][j];
        }
        
    }
    cin >> Q;
    for(int i = 0; i < Q; i ++){
        cin >> r1 >> c1 >> r2>> c2;
        res.push_back(S[r2][c2] - S[r2][c1-1] - S[r1-1][c2] + S[r1-1][c1-1]);
    }
    for(int i = 0; i < Q; i ++){
        cout << res[i] << endl;
    }
    
    

    return 0;
}
