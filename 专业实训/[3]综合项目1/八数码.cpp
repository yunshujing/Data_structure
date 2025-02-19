#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

const string target = "123804765";

int findZero(const string& state) {
    for (int i = 0; i < state.size(); ++i) {
        if (state[i] == '0') {
            return i;
        }
    }
    return -1;
}

string move(const string& state, const string& direction) {
    string newState = state;
    int zeroIndex = findZero(state);
    if (direction == "up" && zeroIndex > 2) {
        swap(newState[zeroIndex], newState[zeroIndex - 3]);
    } else if (direction == "down" && zeroIndex < 6) {
        swap(newState[zeroIndex], newState[zeroIndex + 3]);
    } else if (direction == "left" && zeroIndex % 3!= 0) {
        swap(newState[zeroIndex], newState[zeroIndex - 1]);
    } else if (direction == "right" && zeroIndex % 3!= 2) {
        swap(newState[zeroIndex], newState[zeroIndex + 1]);
    }
    return newState;
}

// BFS 搜索
int bfs(const string& initialState) {
    queue<pair<string, int>> q;
    q.push({initialState, 0});
    unordered_set<string> visited;
    visited.insert(initialState);

    while (!q.empty()) {
        pair<string, int> current = q.front();
        q.pop();
        string state = current.first;
        int steps = current.second;
        if (state == target) {
            return steps;
        }
        vector<string> directions = {"up", "down", "left", "right"};
        for (const string& direction : directions) {
            string newState = move(state, direction);
            if (visited.find(newState) == visited.end()) {
                visited.insert(newState);
                q.push({newState, steps + 1});
            }
        }
    }
    return -1;
}

int main() {
    string initialState;
    cin >> initialState;
    cout << bfs(initialState) << endl;
    return 0;
}