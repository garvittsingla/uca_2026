package DisjointSet;

import java.util.HashSet;

class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] directions = {{-1,0},{0,-1},{1,0},{0,1}};
        DSU ds = new DSU(m*n);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '0') continue;
                for(int idx = 0 ; idx < 4 ; idx++){
                    int dr = directions[idx][0] + i;
                    int dc = directions[idx][1] + j;

                    if(dr < 0 || dc < 0 || dr >= m|| dc >= n || grid[dr][dc] == '0') continue;

                    int index1 = i * n + j;
                    int index2 = dr * n + dc;

                    ds.union(index1,index2);
                }
            }
        }

        HashSet<Integer> st = new HashSet<>();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0') continue;

                int index = i * n + j;
                st.add(ds.findParent(index));
            }
        }
        
        return st.size();
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
       
           char[][] grid = {
               {'1','1','0'},
               {'1','0','0'},
               {'0','0','1'}
           };
       
           int expected = 2;
           int actual = sol.numIslands(grid);
       
           System.out.println(actual == expected ? "PASS" : "FAIL");
    }
}