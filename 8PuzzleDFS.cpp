// #include<bits/stdc++.h>
// using namespace std;


// bool checkEqual(vector<vector<int>> curr, vector<vector<int>> final){
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             if(curr[i][j] != final[i][j])
//                 return false;
//         }
//     }
//     return true;
// }

// pair<int, int> findBlank(vector<vector<int>> curr){
//     pair<int, int> blank;
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             if(curr[i][j] == 0)
//             blank = {i, j};
//         }
//     }
//     return blank;
// }

// void printAns(vector<vector<vector<int>>> vec){
//     for(auto mat : vec){
//         for(auto row : mat){
//             for(auto ele : row){
//                 cout << ele << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// bool dfs(vector<vector<int>>& curr, vector<vector<int>>& final, int depth, int row, int col, set<vector<vector<int>>>& vis, vector<vector<vector<int>>>& vec){
//     if(depth > 10)
//         return false;

//     vec.push_back(curr);
//     vis.insert(curr);

//     if(checkEqual(curr, final)){
//         cout << "The possible solution is : " << endl;
//         printAns(vec);
//         return true;
//     }

//     int delRow[] = {0, 1, 0, -1};
//     int delCol[] = {1, 0, -1, 0};

//     for(int i = 0; i < 4; i++){
//         int nRow = row + delRow[i];
//         int nCol = col + delCol[i];

//         if(nRow >= 0 && nRow < 3 && nCol >= 0 && nCol < 3){
//             swap(curr[row][col], curr[nRow][nCol]);
//             if(!vis.count(curr)){
//                 if(dfs(curr, final, depth + 1, nRow, nCol, vis, vec))
//                     return true;
//             }
//             swap(curr[nRow][nCol], curr[row][col]);
//         }
//     }
//     vec.pop_back();

//     return false;
// }

// int main(){

//     vector<vector<int>> start = {{2, 8, 3},
//                                   {1, 6, 4},
//                                   {7, 0, 5}};
//     vector<vector<int>> final = {{1, 2, 3},
//                                   {8, 0, 4},
//                                   {7, 6, 5}};

//     pair<int, int> blank = findBlank(start);
//     int row = blank.first;
//     int col = blank.second;

//     vector<vector<vector<int>>> ans;
//     set<vector<vector<int>>> vis;

//     if(!dfs(start, final, 0, row, col, vis, ans))
//         cout << "No Solution found" << endl;

//     return 0;

// }

#include <bits/stdc++.h>
using namespace std;

bool checkEqual(const vector<vector<int>>& curr, const vector<vector<int>>& final) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (curr[i][j] != final[i][j])
                return false;
        }
    }
    return true;
}

pair<int, int> findBlank(const vector<vector<int>>& curr) {
    pair<int, int> blank;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (curr[i][j] == 0)
                blank = {i, j};
        }
    }
    return blank;
}

void printAns(const vector<vector<vector<int>>>& vec) {
    for (const auto& mat : vec) {
        for (const auto& row : mat) {
            for (const auto& ele : row) {
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

bool depthLimitedSearch(vector<vector<int>>& curr, const vector<vector<int>>& final, int depth, int limit, int row, int col, set<vector<vector<int>>>& vis, vector<vector<vector<int>>>& vec) {
    if (depth > limit)
        return false;

    vec.push_back(curr);
    vis.insert(curr);

    if (checkEqual(curr, final)) {
        cout << "The possible solution is : " << endl;
        printAns(vec);
        return true;
    }

    int delRow[] = {0, 1, 0, -1};
    int delCol[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; ++i) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if (nRow >= 0 && nRow < 3 && nCol >= 0 && nCol < 3) {
            swap(curr[row][col], curr[nRow][nCol]);
            if (!vis.count(curr)) {
                if (depthLimitedSearch(curr, final, depth + 1, limit, nRow, nCol, vis, vec))
                    return true;
            }
            swap(curr[nRow][nCol], curr[row][col]);
        }
    }
    vec.pop_back();

    return false;
}

int main() {
    vector<vector<int>> start = {{2, 8, 3},
                                 {1, 6, 4},
                                 {7, 0, 5}};
    vector<vector<int>> final = {{1, 2, 3},
                                 {8, 0, 4},
                                 {7, 6, 5}};

    pair<int, int> blank = findBlank(start);
    int row = blank.first;
    int col = blank.second;

    vector<vector<vector<int>>> ans;
    set<vector<vector<int>>> vis;
    int depthLimit = 10;  // Define the depth limit here

    if (!depthLimitedSearch(start, final, 0, depthLimit, row, col, vis, ans))
        cout << "No Solution found within depth limit" << endl;

    return 0;
}
