// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j) {
    if(i < 0 || j < 0 || i > grid.size()-1 || j > grid[i].size()-1 || grid[i][j] == 0) {
        return 0;
    }
    
    int cache = grid[i][j]; // we are storing that so we do not revisit the same index again.
    
    grid[i][j] = 0;
    int up = dfs(grid, i + 1, j);
    int down = dfs(grid, i - 1, j);
    int left = dfs(grid, i, j - 1);
    int right = dfs(grid, i, j + 1);
    
    grid[i][j] = cache;
    return cache + max({up, down, left, right});
}

int maxGold(vector<vector<int>> &grid) {
    int maxans = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] != 0){
                maxans = max(maxans, dfs(grid, i, j));
            }
        }
    }
    return maxans;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    cout << maxGold(grid);

    return 0;
}