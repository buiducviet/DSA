#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(const vector<int>& positions, int distance, int C) {
    int cowsPlaced = 1;
    int lastPosition = positions[0];
    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i] - lastPosition >= distance) {
            cowsPlaced++;
            lastPosition = positions[i];
        }
        if (cowsPlaced == C) // Found a valid configuration
            return true;
    }
    return false;
}

int maxMinDistance(const vector<int>& positions, int C) {
    int left = 0;
    int right = positions.back() - positions.front();
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(positions, mid, C)) {
            result = mid;
            left = mid + 1; // Try to increase the distance
        } else {
            right = mid - 1; // Try to decrease the distance
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, C;
        cin >> N >> C;

        vector<int> positions(N);
        for (int i = 0; i < N; i++) {
            cin >> positions[i];
        }
        
        sort(positions.begin(), positions.end());

        int result = maxMinDistance(positions, C);
        cout << result << endl;
    }

    return 0;
}
