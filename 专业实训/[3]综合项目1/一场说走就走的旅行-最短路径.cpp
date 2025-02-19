/* #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007

const int N = 100005;
int dis[N];
int head[N] = { 0 };
int cnt = 0;
int vis[N] = { 0 };
bool cmp(int a, int b) {
    return a > b;
}
struct edge {
    int to, weight, next;
}a[N];
void add(int u, int v, int w) {
    a[++cnt].weight = w;
    a[cnt].to = v;
    a[cnt].next = head[u];
    head[u] = cnt;
}
struct node {
    int id, w;
    node(int iid, int ww) {
        id = iid;
        w = ww;
    }
    friend bool operator<(node x, node y) {
        return x.w > y.w;
    }
};
priority_queue<node> q;
void dijkstra(int s,int n) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(node(s, 0));
    while (!q.empty()) {
        int u = q.top().id;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = a[i].next) {
            int v = a[i].to, w = a[i].weight;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(node(v, dis[v]));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 0x3f3f3f3f) {
            cout << "impossible";
            if (i != n) cout << " ";
            continue;
        }
        cout << dis[i];
        if (i != n) cout << " ";
    }
    cout << "\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);
    int t;
    cin >> t;
    while (t--) {
        int n, m, pos, u, v, w;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            add(u, v, w);
        }
        cin >> pos;
        dijkstra(pos, n);
        int cnt = 0;
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;
const int INF = 1e7;

int graph[N][N], dist[N], p[N];
bool visited[N];

void Dijkstra(int n, int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = graph[start][i];
        visited[i] = false;
        if (dist[i] == INF) {
            p[i] = -1;
        } else {
            p[i] = start;
        }
    }
    dist[start] = 0;
    visited[start] = true;

    for (int i = 1; i < n; i++) {
        int u = -1, minDist = INF;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }

        if (u == -1) break;

        visited[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] < INF) {
                if (dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                    p[v] = u;
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) graph[i][j] = 0;
                else graph[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (graph[u][v] > w) {
                graph[u][v] = w;
            }
        }

        int pos;
        cin >> pos;

        Dijkstra(n, pos);

        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            if (dist[i] == INF) {
                cout << "impossible";
            } else {
                cout << dist[i];
            }
        }
        cout << endl;
    }

    return 0;
}