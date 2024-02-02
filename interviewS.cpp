#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int calculateSum(const vector<int>& arr) {
    int sum = 0;
    for (int x : arr) {
        sum += x;
    }
    return sum;
}

int calculateSquaredSum(const vector<int>& arr) {
    int sqsum = 0;
    for (int x : arr) {
        sqsum += x * x;
    }
    return sqsum;
}

int binarySearch(int low, int high, const vector<int>& arr, int c) {
    int mid, sum, sqsum;
    while (low <= high) {
        mid = (low + high) / 2;
        sum = calculateSum(arr);
        sqsum = calculateSquaredSum(arr);
        int curr = (sqsum + (2 * mid * sum) + mid * mid * arr.size());
        if (curr == c) {
            return mid;
        } else if (curr < c) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; // Return the closest value if exact match not found
}

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = binarySearch(1, c, arr, c);
    cout << i << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}