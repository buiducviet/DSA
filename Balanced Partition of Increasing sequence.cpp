#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

bool canDivide(const vector<int>& sequence, int m, int threshold) {
    int sum = 0;
    int count = 1;

    for (int num : sequence) {
        sum += num;
        if (sum > threshold) {
            sum = num;
            count++;
        }
    }

    return count <= m;
}
int findMinimalMaxWeight(const vector<int>& sequence, int m, int left, int right) {
    if (left == right) return left;

    int mid = left + (right - left) / 2;
    if (canDivide(sequence, m, mid)) {
        return findMinimalMaxWeight(sequence, m, left, mid);
    } else {
        return findMinimalMaxWeight(sequence, m, mid + 1, right);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    std::vector<int>::size_type n; int m;
    cin >> n >> m;
   vector<int> sequencee;
    for (std::vector<int>::size_type i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        sequencee.push_back(temp);
    }
    int maxElement = 0;
    int sum = 0;
    for(std::vector<int>::size_type i = 0; i < sequencee.size() ; i++){
        sum+= sequencee[i];
        if(maxElement < sequencee[i]) maxElement= sequencee[i];
    }
        
    
    int minimalMaxWeight = findMinimalMaxWeight(sequencee, m, maxElement, sum);
    cout << minimalMaxWeight << endl;

    return 0;
}