#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void bfs(const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& order) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int vertex = q.front();
                q.pop();
                order.push_back(vertex);
                for (int j = 0; j < n; ++j) {
                    if (graph[vertex][j] == 1 &&!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(n, false);
    vector<int> order;

    bfs(graph, visited, order);

    for (int num : order) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}