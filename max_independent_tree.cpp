#include <bits/stdc++.h>
using namespace std;

struct Node {
    int weight;
    vector<int> children;
};

int maxWeightSum(const vector<Node>& tree, vector<vector<int>>& dp, int u, int parent) {
    if (dp[u][parent] != -1) return dp[u][parent];

    int include = tree[u].weight;
    for (int v : tree[u].children) {
        if (v != parent) {
            int sumExcludeV = 0;
            for (int w : tree[v].children) {
                if (w != u) {
                    sumExcludeV += maxWeightSum(tree, dp, w, v);
                }
            }
            include += sumExcludeV;
        }
    }

    int exclude = 0;
    for (int v : tree[u].children) {
        if (v != parent) {
            exclude += maxWeightSum(tree, dp, v, u);
        }
    }

    return dp[u][parent] = max(include, exclude);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<Node> tree(n+1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].weight;
    }

    // Khởi tạo cây
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].children.push_back(v);
        tree[v].children.push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int maxWeight = maxWeightSum(tree, dp, 1, 0);
    cout << maxWeight << endl;

    return 0;
}
