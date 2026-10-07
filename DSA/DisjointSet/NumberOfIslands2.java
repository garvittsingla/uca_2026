package DisjointSet;

import java.util.ArrayList;
import java.util.Arrays;

import DisjointSet.DSU;
public class NumberOfIslands2 {
    class Solution {
        
       
        public ArrayList<Integer> numOfIslands(int m, int n, int[][] operators) {
            ArrayList<Integer> ans = new ArrayList<>();
            int count = 0;
            
            DSU ds = new DSU(m*n);
            
            int[][] directions = {{-1,0},{0,-1},{1,0},{0,1}};
            
            int[][] vis = new int[m][n];
            for(int i = 0 ; i < m ; i++){
                for(int j = 0;j<n ; j++){
                    vis[i][j] = 0;
                }
            }
            
            for(int i = 0 ; i < operators.length ; i++){
                int row = operators[i][0];
                int col = operators[i][1];
                
                if(vis[row][col] == 1){
                    ans.add(count);
                    continue;
                }
                
                vis[row][col] = 1;
                count++;
                
                int current = row*n+col;
                
                for(int j = 0 ; j < 4 ; j++){
                    int dr = directions[j][0] + row;
                    int dc = directions[j][1] + col;
                    
                    if(dr < 0 || dc < 0 || dr >= m || dc >= n || vis[dr][dc] == 0) continue;
                    
                    int nei = dr * n + dc;
                    
                    if(ds.findParent(nei) != ds.findParent(current)){
                        ds.union(nei,current);
                        count--;
                    }
                }
                 ans.add(count);
            }
           return ans;
            
            
        }
        
    }
    public static void main(String[] args) {
        NumberOfIslands2 obj = new NumberOfIslands2();
           Solution sol = obj.new Solution();
       
           int[][] operators = {
               {0, 0},
               {0, 1},
               {1, 2},
               {1, 1}
           };
       
           ArrayList<Integer> expected = new ArrayList<>(Arrays.asList(1, 1, 2, 1));
           ArrayList<Integer> actual = sol.numOfIslands(2, 3, operators);
       
           System.out.println(actual.equals(expected) ? "PASS" : "FAIL");
        
    }
}