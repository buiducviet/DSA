
#include <bits/stdc++.h>
using namespace std;
#define MaxN 32
int m; // teacher quantity
int n; // course quantity
int conflict_count ;
vector<vector<int>> teacher_list(32); // list teacher of each course;
int conflict[MaxN][MaxN];
int X[MaxN];
int maxLoad=1000;
int currentload[32]={0};
void input(){
    cin >> m >> n;
    for (int i = 1 ; i <= m; i++){
        int temp;
        cin >> temp;
        for(int j = 1 ; j <= temp; j++ ){
            int course;
            cin >> course;
            teacher_list[course].push_back(i);
        }
    }
    cin >> conflict_count;
    for(int i = 0; i < conflict_count; i++){
        int course_1, course_2;
        cin >> course_1 >> course_2;
        conflict[course_1][course_2]=1;
        conflict[course_2][course_1]=1;
    }
}
int check(int v, int k){
    for(int i = 1; i <= k-1; i++){
        if(conflict[i][k] && v == X[i]) return 0;
    }
    return 1;
}
void solution(){
    int max =0;
    /*for(int t = 1; t <= m; t++){
        int temp=0;
        for(int i = 1; i <= n; i++) if(X[i] == t) temp++;
        if (temp > max) max= temp;
    }*/
    for(int i =1; i <=m; i++){
        if(currentload[i]>max) max = currentload[i];
    }
    if (max < maxLoad) maxLoad = max;
}
void TRY(int k){
    for(int i = 0; i < teacher_list[k].size(); i++){
        int v = teacher_list[k][i];
        if(check(v,k)){
            X[k] = v;
            currentload[v]++;
            if(k == n){
                solution();
            }else{
                TRY(k+1);
                
            }
            currentload[v]--;
        }
    }
}
void solve(){
    TRY(1);
    cout << maxLoad;
}
int main(){
    input();
    solve();
    return 0;
}
