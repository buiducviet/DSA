
/*Dynamic Programming Solution*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 +5;
int a[N];
int mem[N];
bool mark[N];
int MaxSum(int i){
    if(i==1) return a[i];
    if(mark[i]== true) return mem[i];
    int res= max(a[i], a[i]+MaxSum(i-1));
    mark[i]=true;
    mem[i]=res;
    return res;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <=n; i++){
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        MaxSum(i);
        ans = max(ans, mem[i]);
    }
    cout << ans;
    return 0;
}