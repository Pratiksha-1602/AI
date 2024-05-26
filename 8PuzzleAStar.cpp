#include <bits/stdc++.h>
using namespace std;

int countMisplaced(vector<vector<int>> curr, vector<vector<int>> goal){
    int count=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(curr[i][j]!=0 && curr[i][j] != goal[i][j]){
                count++;
            }
        }
    }
    return count;
}

void printAss(vector<vector<int>> &ans){
    
        for(auto row:ans){
            for(auto ele:row){
                cout << ele << " ";
            }
            cout << endl;
        }
        cout<<endl;
}

pair<int, int> findBlank(vector<vector<int>> curr){
    pair<int, int> ans;
    for(int i=0;i<3;i++){
        for(int j = 0; j<3;j++){
            if(curr[i][j] == 0){
                ans = {i,j};
                break;
            }
        }
    }
    return ans;
}

void bestFirstSearch(vector<vector<int>> start, vector<vector<int>> goal){
    // priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>, greater<>>> pq;
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, greater<>> pq;
    int h = countMisplaced(start, goal);
    int g = 0;
    pq.push({h+g, start});
    int delrow[] = {0,1,0,-1};
    int delcol[] = {1,0,-1,0};

    while(!pq.empty()){
        vector<vector<int>> curr = pq.top().second;
        pq.pop();
        printAss(curr);
        h = countMisplaced(curr, goal);
        cout<<"h = "<<h<<endl;
        cout<<"g = "<<g<<endl;
        if(h==0){
            cout<<"Solution found." <<endl;
            break;
        }
        g++;
        pair<int,int> blank = findBlank(curr);
        int row = blank.first;
        int col = blank.second;
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<3 && ncol>=0 && ncol<3){
                swap(curr[row][col], curr[nrow][ncol]);
                h = countMisplaced(curr, goal);
                pq.push({h+g, curr});
                swap(curr[row][col], curr[nrow][ncol]);
            }
        }
    }
}

int main(){
    vector<vector<int>> start={{2,8,3},{1,6,4},{7,0,5}};
    vector<vector<int>> goal={{1,2,3},{8,0,4},{7,6,5}};

    bestFirstSearch(start, goal);
    return 0;
}
