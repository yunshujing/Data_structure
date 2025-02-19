#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;


// 马的8种可能移动方向
const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// 将坐标转换为字符串
string coordToString(int x, int y) {
    return string(1, 'a' + x) + to_string(y + 1);
}

// 将字符串转换为坐标
void stringToCoord(const string& s, int& x, int& y) {
    x = s[0] - 'a';
    y = s[1] - '1';
}

// 计算马从一个位置到另一个位置的最少步数
int minKnightMoves(const string& start, const string& end) {
    int startX, startY, endX, endY;
    stringToCoord(start, startX, startY);
    stringToCoord(end, endX, endY);

    if (start == end) return 0;

    queue<pair<int, int>> q;
    unordered_map<string, bool> visited;
    q.push({ startX, startY });
    visited[start] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;

            if (x == endX && y == endY) {
                return steps;
            }

            for (int j = 0; j < 8; ++j) {
                int newX = x + dx[j];
                int newY = y + dy[j];
                if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
                    string newCoord = coordToString(newX, newY);
                    if (!visited[newCoord]) {
                        q.push({ newX, newY });
                        visited[newCoord] = true;
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout << setw(3);
    cout << fixed << setprecision(6);
    
    string start, end;
    while (cin >> start >> end) {
        int moves = minKnightMoves(start, end);
        cout << "To get from " << start << " to " << end << " takes " << moves << " knight moves." << endl;
    }
    return 0;
}