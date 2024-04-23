#include <bits/stdc++.h>
using namespace std;

void findMinRoute(vector<vector<int> > tsp, int n)
{
    int sum = 0;
    int minSum = INT_MAX;
    int minRoute[n];
    vector<int> route;
    vector<int> minRouteVec;

    // Duyệt qua từng thành phố từ thành phố 0
    for (int start = 0; start < n; ++start) {
        sum = 0;
        route.clear();
        route.push_back(start);
        vector<bool> visited(n, false);
        visited[start] = true;

        int cur = start;

        // Tìm đường đi từ thành phố hiện tại
        for (int i = 0; i < n - 1; ++i) {
            int next = -1;
            int minCost = INT_MAX;

            // Duyệt qua các thành phố chưa thăm qua
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && tsp[cur][j] < minCost) {
                    minCost = tsp[cur][j];
                    next = j;
                }
            }

            // Thêm thành phố tiếp theo vào đường đi
            route.push_back(next);
            sum += minCost;
            visited[next] = true;
            cur = next;
        }

        // Thêm thành phố cuối cùng vào đường đi
        route.push_back(start);
        sum += tsp[cur][start];

        // Lưu đường đi có tổng chi phí nhỏ nhất
        if (sum < minSum) {
            minSum = sum;
            minRouteVec = route;
        }
    }

   /* cout << "Minimum Cost is : " << minSum << endl;*/

   /* cout << "Route: ";*/
    for (int i = 0; i < minRouteVec.size()-1; ++i) {
        cout << minRouteVec[i] + 1 << " "; // Thêm 1 để đánh số thành phố từ 1 thay vì 0
    }
    /* int s=0;*/
    /*for(int i = 0; i <minRouteVec.size()-1; i++){
        s+= tsp[minRouteVec[i]][minRouteVec[i+1]];
    }
    s+= tsp[minRouteVec[minRouteVec.size()-1]][minRouteVec[0]];
    cout << endl;
    cout << "s: " << s;*/
}

int main()
{
    int n;
    /*cout << "Enter the number of cities: ";*/
    cin >> n;

    vector<vector<int> > tsp(n, vector<int>(n));
   /* cout << "Enter the cost matrix: " << endl;*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tsp[i][j];
        }
    }
    cout << n << endl;
    findMinRoute(tsp, n);

    return 0;
}
