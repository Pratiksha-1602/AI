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

bool iterativeDFS(vector<vector<int>> start, vector<vector<int>> goal, int row, int col, vector<vector<vector<int>>> &ans) {
    set<vector<vector<int>>> vis;
    stack<pair<vector<vector<int>>, vector<vector<vector<int>>>>> s;
    stack<pair<int, int>> posStack;
    stack<int> depthStack;

    s.push({start, {}});
    posStack.push({row, col});
    depthStack.push(0);

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    while (!s.empty()) {
        auto current = s.top();
        s.pop();
        auto pos = posStack.top();
        posStack.pop();
        int depth = depthStack.top();
        depthStack.pop();

        vector<vector<int>> curr = current.first;
        vector<vector<vector<int>>> path = current.second;
        int currRow = pos.first;
        int currCol = pos.second;

        if (depth > 10) {
            continue;
        }

        path.push_back(curr);
        vis.insert(curr);

        if (checkEqual(curr, goal)) {
            cout << "Possible solution: " << endl;
            printAss(path);
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nrow = currRow + delrow[i];
            int ncol = currCol + delcol[i];

            if (nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 3) {
                swap(curr[currRow][currCol], curr[nrow][ncol]);
                if (!vis.count(curr)) {
                    s.push({curr, path});
                    posStack.push({nrow, ncol});
                    depthStack.push(depth + 1);
                }
                swap(curr[currRow][currCol], curr[nrow][ncol]);
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> start = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}};
    vector<vector<int>> goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};

    pair<int, int> blank = findBlank(start);
    vector<vector<vector<int>>> ans;

    if (!iterativeDFS(start, goal, blank.first, blank.second, ans)) {
        cout << "No solution" << endl;
    }
    return 0;
}
