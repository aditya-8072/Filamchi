#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int stepsNeeded(int n, int x, int y, int a[]) {
    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // <position, steps>

    // Check if starting position is valid
    if (a[0] == 0) return -1;
    
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        int pos = front.first;
        int steps = front.second;
        q.pop();

        if (pos == n - 1)
            return steps;

        // Right jumps
        for (int i = 1; i <= y; ++i) {
            int next = pos + i;
            if (next < n && !visited[next] && a[next] == 1) {
                visited[next] = true;
                q.push({next, steps + 1});
            }
        }

        // Left jumps
        for (int i = 1; i <= x; ++i) {
            int next = pos - i;
            if (next >= 0 && !visited[next] && a[next] == 1) {
                visited[next] = true;
                q.push({next, steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << stepsNeeded(n, x, y, a);
    return 0;
}