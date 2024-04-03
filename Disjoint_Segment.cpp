#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
bool checkjoint(p &a, p &b){
    if(a.second < b.first){
        return true;
    }
    return false;
}
bool compareSecond(p &a, p &b){
    return a.second < b.second;
}
int main(){
    int n; 
    cin >> n;
    vector<p> A;
    vector<p> input;;
    for(int i=0; i <n; i++){
        p x;
        cin >> x.first >> x.second;
        input.push_back(x);
    }
    sort(input.begin(), input.end(), compareSecond);
    A.push_back(input[0]);
    for(int i =1; i < n; i++){
        if(checkjoint(A[A.size()-1],input[i])){
            A.push_back(input[i]);
        }
    }
    cout << A.size();
    return 0;
    

}