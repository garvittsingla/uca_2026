import java.util.*;
public class numberOfIslands {
    
    public static void bfs(char[][] grid, boolean[][] visited,int row,int col) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{row, col});
        visited[row][col] = true;
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0], c = cell[1];
            for(int[] dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1' && !visited[nr][nc]) {
                    queue.add(new int[]{nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }

    public static int numOfIslands(char[][] grid) {
       int m = grid.length,n = grid[0].length;
       boolean[][] visited = new boolean[m][n];
       int count = 0;
       
       for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
               if(grid[i][j] == '1' && !visited[i][j]) {
                   bfs(grid, visited, i, j);
                   count++;
               }
           }
       }
        return count;
    }

    public static void main(String[] args) {
        char[][] grid1 = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        };
        System.out.println(numOfIslands(grid1));

        char[][] grid2 = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
        };
        System.out.println(numOfIslands(grid2));
    }
}