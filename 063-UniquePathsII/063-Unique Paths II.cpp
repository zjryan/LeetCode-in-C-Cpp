class Solution {
public:
    enum { obs = 65535 };
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        if(n == 0 || m == 0) return 0;
        vector<vector<int>> table;
        for(int i = 0; i < n; i++){
            vector<int> tmp(m, 0);
            table.push_back(tmp);
            for(int j = 0; j < m; j++){
                if(obstacleGrid[i][j] == 1)
                    table[i][j] = obs;
            }
        }
        if(table[0][0] != obs)
            table[0][0] = 1;
        for(int j = 1; j < m; j++){
            if(table[0][j] == obs) continue;
            if(table[0][j - 1] == obs) table[0][j] = 0;
            else table[0][j] = table[0][j - 1];
        }
        for(int i = 1; i < n; i++){
            if(table[i][0] == obs) continue;
            if(table[i - 1][0] == obs) table[i][0] = 0;
            else table[i][0] = table[i - 1][0];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(table[i][j] == obs) continue;
                if(table[i - 1][j] == obs && table[i][j - 1] == obs) table[i][j] = 0;
                else if(table[i - 1][j] == obs) table[i][j] = table[i][j - 1];
                else if(table[i][j - 1] == obs) table[i][j] = table[i - 1][j];
                else table[i][j] = table[i - 1][j] + table[i][j - 1];
            }
        }
        if(table[n - 1][m - 1] != obs) return table[n - 1][m - 1];
        else return 0;
    }
};
