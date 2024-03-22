#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0;
    int current_sum = 0;
    int max_length = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += a[right]; // Add a[right] to current_sum

        while (current_sum > Q) {
            current_sum -= a[left]; // Subtract a[left] from current_sum
            ++left;
        }


        max_length = max(max_length, right - left + 1);
    }

    if (max_length == 0) {
        cout << -1 << endl;
    } else {
        cout << max_length << endl;
    }

    return 0;
}
