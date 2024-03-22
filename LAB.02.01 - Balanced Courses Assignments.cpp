
#include <bits/stdc++.h>
using namespace std;
#define MaxN 32
int m; // teacher quantity
int n; // course quantity
int conflict_count ;
vector<vector<int>> teacher_list(32); // list teacher of each course;
int conflict[MaxN][MaxN];
int X[MaxN];
int maxLoad;
int cnt;
int currentLoad[MaxN] = {0};
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

void TRY(int k){
    for(int i = 0; i < teacher_list[k].size(); i++){
        int v = teacher_list[k][i];
        if(check(v,k)){
            X[k] = v;
            if(k == n){

                /*for(int j = 1; j <= n; j++) {
                    currentLoad[X[j]]++;
                }
                // Cập nhật maxLoad
                maxLoad = *max_element(currentLoad + 1, currentLoad + m + 1);*/
                cnt++;
            }else{
                TRY(k+1);
            }
        }
    }
}
void solve(){
    cnt = 0;
    TRY(1);
}
int main(){
    input();
    solve();
    cout << cnt;
    return 0;
}
