class Solution {
public:
    using ll = long long;

    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        ll ans = 0;

        ll rowSize = grid.size();
        ll colSize = grid[0].size();

        // count 1s in every row and column
        vector<ll> row(rowSize , 0) , col(colSize , 0);

        for(int i = 0 ; i < rowSize ; i++){
            for(int j = 0 ; j < colSize ; j++){
                // this elements will contribute to ith row and jth col
                if(grid[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // now calculate number of triangles at each center
        for(int i = 0 ; i  < rowSize ; i++){
            for(int j = 0 ; j < colSize ; j++){
                if(grid[i][j] == 0) continue;
                
                ll rowCnt = row[i] - 1;
                ll colCnt = col[j] - 1;

                ans += rowCnt * colCnt;
            }
        }

        return ans;
    }
};
