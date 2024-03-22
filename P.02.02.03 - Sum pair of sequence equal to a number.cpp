// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the count of pairs
int getPairsCount(int arr[], int n, int k)
{
	sort(arr, arr + n);
	int x = 0, c = 0, y, z;
	for (int i = 0; i < n - 1; i++) {
		x = k - arr[i];

		// Lower bound from i+1
		int y = lower_bound(arr + i + 1, arr + n, x) - arr;

		// Upper bound from i+1
		int z = upper_bound(arr + i + 1, arr + n, x) - arr;
		c = c + z - y;
	}
	return c;
}

// Driver code
int main()
{
	int n, M;
    cin >> n >> M;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
	cout << getPairsCount(a, n, M);
	return 0;
}
