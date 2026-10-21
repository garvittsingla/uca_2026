/*
 * ============================================================================
 *  Daily Assignment - 14/Oct/2026
 *  Question 1 of 2: Maximize Minimum of Pairwise Row Maximums
 *  Platform: geek101.dev
 *  Company: ServiceNow 2025
 *  Language: Java
 *  Verdict: Accepted (7/7 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Given a 2D matrix of size R x C, you need to select two distinct rows, say row i and row j (0 <= i, j < R, i != j).
 *
 * From these two rows, we construct a new array A of size C where the k-th element is the maximum of the elements at the k-th index of both rows:
 * A[k] = max(matrix[i][k], matrix[j][k])     for  0 <= k < C
 *
 * Your goal is to choose the two distinct rows i and j such that the minimum element of the resulting array A is maximized.
 *
 * Return this maximum possible minimum value.
 *
 * Input Format
 * - The first line contains two space-separated integers R and C, representing the number of rows and columns of the matrix.
 * - The next R lines each contain C space-separated integers representing the elements of the matrix.
 *
 * Output Format
 * - Print a single integer, the maximum possible minimum value of the array A obtained by choosing two distinct rows.
 *
 * Constraints
 * - 2 <= R <= 1000
 * - 1 <= C <= 12
 * - 1 <= matrix[i][j] <= 10^9
 *
 * Examples
 *
 * Example 1
 * Input:
 *
 * 3 3
 * 3 2 5
 * 4 1 3
 * 2 6 2
 *
 * Output:
 *
 * 3
 *
 * Explanation:
 * - If we choose row 0 ([3, 2, 5]) and row 2 ([2, 6, 2]), the pairwise maximums are [max(3,2), max(2,6), max(5,2)] = [3, 6, 5]. The minimum of this array is 3.
 * - If we choose row 1 ([4, 1, 3]) and row 2 ([2, 6, 2]), the pairwise maximums are [max(4,2), max(1,6), max(3,2)] = [4, 6, 3]. The minimum of this array is 3.
 * - Any other choice yields a minimum less than or equal to 3. Thus, the maximum possible minimum is 3.
 *
 * Example 2
 * Input:
 *
 * 2 4
 * 10 20 30 40
 * 40 30 20 10
 *
 * Output:
 *
 * 30
 *
 * Explanation:
 * - Since there are only 2 rows, we must choose row 0 and row 1.
 * - The pairwise maximums are [max(10,40), max(20,30), max(30,20), max(40,10)] = [40, 30, 30, 40].
 * - The minimum of this array is 30.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.io.*;
import java.util.*;

public class Q1_MaximizeMinimumOfPairwiseRowMaximums {
    public static int maximizeMinimum(int m, int n, int[][] matrix) {
         int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            int minVal = Integer.MAX_VALUE;

            for (int k = 0; k < n; k++) {
                int maxVal = Math.max(matrix[i][k], matrix[j][k]);
                minVal = Math.min(minVal, maxVal);
            }

            ans = Math.max(ans, minVal);
        }
    }

    return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        String[] parts = line.trim().split("\\s+");
        int R = Integer.parseInt(parts[0]);
        int C = Integer.parseInt(parts[1]);
        int[][] matrix = new int[R][C];
        for (int i = 0; i < R; i++) {
            line = br.readLine();
            if (line == null) break;
            parts = line.trim().split("\\s+");
            for (int j = 0; j < C; j++) {
                matrix[i][j] = Integer.parseInt(parts[j]);
            }
        }
        System.out.println(maximizeMinimum(R, C, matrix));
    }
}
