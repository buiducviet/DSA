
#include <bits/stdc++.h>
using namespace std;
struct Treasure {
    int x;
    int y;
    long long int gold;
};
const int MAX=1001;
int n;


bool compareTreasure(const Treasure &a, const Treasure &b) {
     if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main()
{
    cin >> n;
    vector<Treasure> Treasure_list(n);
    for(int i = 0; i < n ; i++){
        cin >> Treasure_list[i].x >> Treasure_list[i].y >> Treasure_list[i].gold;
    }
     sort(Treasure_list.begin(), Treasure_list.end(), compareTreasure);
     /*for(int i = 0; i < n ; i++){
        cout << Treasure_list[i].x << " " << Treasure_list[i].y << "; ";
    }*/
    vector<long long int> dp(n);
    dp[0]=Treasure_list[0].gold;
   
    for (int i = 1; i < n; ++i) {
         dp[i] = Treasure_list[i].gold;
        for (int j = 0; j < i; ++j) {

            if (Treasure_list[j].x <= Treasure_list[i].x && Treasure_list[j].y <= Treasure_list[i].y) {
                dp[i] = max(dp[i], dp[j] + Treasure_list[i].gold);
            }
        }
    }
    long long int max=0;
    /*cout << endl;*/
    for(int i = 0; i < n; i++){
        
        if(max < dp[i]) max = dp[i];
    }
    /*cout << endl;*/
    cout << max;
    return 0;
}