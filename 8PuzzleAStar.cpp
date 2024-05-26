#include <bits/stdc++.h>
using namespace std;

int countMisplaced(vector<vector<int>> &curr, vector<vector<int>> &final)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (curr[i][j] != 0 && curr[i][j] != final[i][j])
                count++;
        }
    }
    return count;
}

pair<int, int> findBlank(vector<vector<int>> vec)
{
    pair<int, int> ans;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (vec[i][j] == 0)
                ans = {i, j};
        }
    }
    return ans;
}

void printState(vector<vector<int>> state)
{
    for (auto row : state)
    {
        for (auto el : row)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> start = {{2, 8, 3},
                                 {1, 6, 4},
                                 {7, 0, 5}};
    vector<vector<int>> final = {{1, 2, 3},
                                 {8, 0, 4},
                                 {7, 6, 5}};

    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, greater<>> pq;
    int h = countMisplaced(start, final);
    int g = 0;
    pq.push({g + h, start});

    //              R  D   L  U
    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    while (!pq.empty())
    {
        vector<vector<int>> curr = pq.top().second;
        pq.pop();
        printState(curr);

        h = countMisplaced(curr, final);
        cout << "g = " << g << endl;
        cout << "h = " << h << endl
             << endl;

        if (h == 0)
        {
            cout << "Solution found!" << endl;
            break;
        }

        g++;

        pair<int, int> blank = findBlank(curr);
        int row = blank.first;
        int col = blank.second;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 3)
            {
                swap(curr[row][col], curr[nrow][ncol]);
                h = countMisplaced(curr, final);
                pq.push({g + h, curr});
                swap(curr[row][col], curr[nrow][ncol]);
            }
        }
    }
    return 0;
}
