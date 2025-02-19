#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

// 检查是否越界
bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

// 深度优先搜索标记同一细胞
void dfs(vector<vector<int>>& matrix, int x, int y) {
    if (!isValid(x, y, matrix.size(), matrix[0].size()) || matrix[x][y] == 0) {
        return;
    }
    // 标记已经访问过
    matrix[x][y] = 0;
    // 向上下左右四个方向进行深度优先搜索
    dfs(matrix, x + 1, y);
    dfs(matrix, x - 1, y);
    dfs(matrix, x, y + 1);
    dfs(matrix, x, y - 1);
}

int countCells(vector<vector<int>>& matrix) {
    int count = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] > 0) {
                count++;
                dfs(matrix, i, j);
            }
        }
    }
    return count;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout << setw(3);
    cout << fixed << setprecision(6);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char num;
            cin >> num;
            matrix[i][j] = num - '0';
        }
    }
    int cellCount = countCells(matrix);
    cout << cellCount << endl;
    return 0;
}