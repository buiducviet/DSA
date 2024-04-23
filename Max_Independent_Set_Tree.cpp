#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100001;
int M0[MAX_N];
int M1[MAX_N];
vector<vector<int>> adj(MAX_N);
int S0(int v, int parent), S1(int v, int parent);
int S(int v, int parent);
int n; 
int weight[MAX_N];

int S(int v, int parent){
    return max(S0(v,parent), S1(v,parent));
}

int S0(int v, int parent){
    if(adj[v].empty()){
        M0[v] = 0;
        return 0;
    }
    if(M0[v] == -1){
        M0[v] = 0;
        for(int i= 0; i < adj[v].size(); i++){
            if(adj[v][i]!=parent)
                M0[v] = M0[v] + S(adj[v][i],v);
        }
    }
    return M0[v];
}

int S1(int v, int parent){
    if(adj[v].empty()){
        M1[v] = weight[v];
        return weight[v];
    }
    if(M1[v] == -1){
        M1[v] = weight[v];
        for(int i= 0; i < adj[v].size(); i++){
            
            if(adj[v][i]!=parent)
                M1[v] = M1[v] + S0(adj[v][i],v);
        }
    }
    return M1[v];
}


int main(){

    cin >> n;
    
    for(int i = 1; i<= n; i++){
        cin >> weight[i]; // weight[i] = trong so dinh thu i
    }
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i <= n; i++){
        M0[i] = -1;
        M1[i] = -1;
    }
   int res  = S(1,0);
    cout << res << endl;
    return 0;

}