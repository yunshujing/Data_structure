#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

// 检查坐标是否在矩阵范围内
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// 对边界上的0进行深度优先搜索，标记为已访问
void dfs(vector<vector<int>>& grid, int x, int y) {
    if (!isValid(x, y, grid.size(), grid[0].size()) || grid[x][y]!= 0) {
        return;
    }
    grid[x][y] = -1; // 标记为已访问
    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
}

int countEnclosedArea(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // 对第一行和最后一行进行DFS
    for (int i = 0; i < cols; ++i) {
        if (grid[0][i] == 0) {
            dfs(grid, 0, i);
        }
        if (grid[rows - 1][i] == 0) {
            dfs(grid, rows - 1, i);
        }
    }

    // 对第一列和最后一列进行DFS
    for (int i = 0; i < rows; ++i) {
        if (grid[i][0] == 0) {
            dfs(grid, i, 0);
        }
        if (grid[i][cols - 1] == 0) {
            dfs(grid, i, cols - 1);
        }
    }

    int count = 0;
    // 统计被1包围的0的数量
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                count++;
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
    
    vector<vector<int>> grid(10, vector<int>(10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> grid[i][j];
        }
    }
    int area = countEnclosedArea(grid);
    cout << area << endl;
    return 0;
}