#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001;
int T;// testcase number;

bool check(int dis, int c, vector<int> x){
    int cur = x[0];
    int total = 1;
    int n = x.size();
    for(int i = 1; i < n; i++){
        if(x[i]-cur >= dis){
            total++;
            cur=x[i];
        }
        if(total == c) return true;

    }
    return false;
}
int binary_maxdistance(const vector<int> &x, int c){
        int left = 0;
        int right = (x.back() - x.front())/(c-1)+1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(mid, c, x)) {
                result = mid;
                left = mid + 1; // Try to increase the distance
            } else {
                right = mid - 1; // Try to decrease the distance
            }
        }

        return result;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        int n, c;
        vector<int> x;
        cin >> n >> c;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            x.push_back(temp);
        }
        sort(x.begin(), x.end());
        cout << binary_maxdistance(x, c) << endl;
        
    }
    
    return 0;
}