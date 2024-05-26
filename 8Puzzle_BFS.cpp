#include <bits/stdc++.h>
using namespace std;

bool checkEqual(vector<vector<int>> curr, vector<vector<int>> final)
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (curr[i][j] != final[i][j])
            return false;
      }
   }
   return true;
}

pair<int, int> findBlank(vector<vector<int>> curr)
{
   pair<int, int> blank;
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (curr[i][j] == 0)
            blank = {i, j};
      }
   }
   return blank;
}

void printAns(vector<vector<vector<int>>> vec)
{
   for (auto mat : vec)
   {
      for (auto row : mat)
      {
         for (auto element : row)
         {
            cout << element << " ";
         }
         cout << endl;
      }
      cout << endl;
   }
}

int main()
{
   vector<vector<int>> start = {{2, 8, 3},
                                {1, 6, 4},
                                {7, 0, 5}};
   vector<vector<int>> final = {{1, 2, 3},
                                {8, 0, 4},
                                {7, 6, 5}};
   vector<vector<vector<int>>> ans;
   queue<pair<vector<vector<int>>, vector<vector<vector<int>>>>> q;

   q.push({start, ans});
   //              R  D   L  U
   int delrow[] = {0, 1, 0, -1};
   int delcol[] = {1, 0, -1, 0};
   while (!q.empty())
   {
      bool flag = false;
      int size = q.size();
      while (size--)
      {
         vector<vector<int>> curr = q.front().first;
         vector<vector<vector<int>>> vec = q.front().second;
         q.pop();
         if (checkEqual(curr, final))
         {
            cout << "Possible solution:" << endl
                 << endl;
            printAns(vec);
            flag = true;
            break;
         }
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
               vec.push_back(curr);
               q.push({curr, vec});
               vec.pop_back();
               swap(curr[row][col], curr[nrow][ncol]);
            }
         }
      }
      if (flag)
         break;
   }
   return 0;
}
