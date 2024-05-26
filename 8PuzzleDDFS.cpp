#include <bits/stdc++.h>
using namespace std;

void printAss(vector<vector<vector<int>>> &ans) {
    for (auto mac : ans) {
        for (auto row : mac) {
            for (auto ele : row) {
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool checkEqual(vector<vector<int>> start, vector<vector<int>> goal) {
    return start == goal;
}

pair<int, int> findBlank(vector<vector<int>> curr) {
    pair<int, int> ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (curr[i][j] == 0) {
                ans = {i, j};
                break;
            }
        }
    }
    return ans;
}

bool dfs(vector<vector<int>> &start, vector<vector<int>> &goal, int depth, int row, int col, set<vector<vector<int>>> &vis, vector<vector<vector<int>>> &ans, int limit) {
    if (depth > limit) {
        return false;
    }

    ans.push_back(start);
    vis.insert(start);

    if (checkEqual(start, goal)) {
        cout << "Possible solution: " << endl;
        printAss(ans);
        return true;
    }

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 3) {
            swap(start[row][col], start[nrow][ncol]);
            if (!vis.count(start)) {
                if (dfs(start, goal, depth + 1, nrow, ncol, vis, ans, limit)) {
                    return true;
                }
            }
            swap(start[row][col], start[nrow][ncol]);
        }
    }
    ans.pop_back();
    return false;
}

bool iddfs(vector<vector<int>> &start, vector<vector<int>> &goal, int max_depth) {
    pair<int, int> blank = findBlank(start);
    vector<vector<vector<int>>> ans;
    set<vector<vector<int>>> vis;

    for (int limit = 0; limit <= max_depth; limit++) {
        vis.clear();
        ans.clear();
        if (dfs(start, goal, 0, blank.first, blank.second, vis, ans, limit)) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> start = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}};
    vector<vector<int>> goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
    int max_depth = 20; // Adjust as needed

    if (!iddfs(start, goal, max_depth)) {
        cout << "No solution" << endl;
    }
    return 0;
}
