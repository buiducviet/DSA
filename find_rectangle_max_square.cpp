#include<bits/stdc++.h>
using namespace std;
#define MaxN 10002
int A[MaxN][MaxN];
int h[MaxN];
int R[MaxN], L[MaxN];
vector<int> V;
int m, n;
// scan input and add into array
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j= 1; j <=m; j++){
           scanf("%d", &A[i][j]);
        }
    }
    

}
// calculate() funtion to compute max square
int calculate(){
    int res=0;
    // set virtual edge with 
    h[0] = -1;
    h[m+1] = -1;
    for(int i = 1; i <= m+1; i++){
        while(!V.empty() && h[i] < h[V[V.size()-1]]){
            R[V[V.size()-1]]=i;
            V.pop_back();
            
        }
        V.push_back(i);
    
    }
    for(int i = m; i >= 0; i--){
        while(!V.empty() && h[i] < h[V[V.size()-1]]){
            L[V[V.size()-1]]=i;
            V.pop_back();
            
        }
        V.push_back(i);    

    }
    for(int i = 0 ; i <= m+1; i++){
        res= ( res <  (R[i]-L[i]-1)*h[i] ) ?  (R[i]-L[i]-1)*h[i]  : res;
   }
    
    return  res;
    

}
void solve(){
        for(int j = 0; j < m+1; j++ ){
            h[j]= 0;
        }
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j < m+1; j++ ){
            if(A[i][j] == 0) h[j] = 0;
            else h[j]+=1;
        }
    }
    cout << calculate();
    
}
int main(){
    /*freopen("input_find_min_square.txt", "r", stdin);*/
    input();
    solve();
    return 0;
}