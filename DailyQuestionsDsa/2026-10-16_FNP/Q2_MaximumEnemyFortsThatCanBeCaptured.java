/*
 * ============================================================================
 *  Daily Assignment - 16/Oct/2026
 *  Question 2 of 2: Maximum Enemy Forts That Can Be Captured
 *  Platform: geek101.dev
 *  Company: FNP
 *  Language: Java
 *  Verdict: Accepted (8/8 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * You are given a 0-indexed integer array forts of length n representing the positions of several forts. forts[i] can be:
 * - 1 representing a fort under your command.
 * - -1 representing an empty gate.
 * - 0 representing an enemy fort.
 *
 * You want to move your army from one of your forts to an empty gate. During this move, you can capture all enemy forts in between. Capture is only possible if:
 * - You move from a fort under your command (1) to an empty gate (-1), or vice versa.
 * - All forts between them are enemy forts (0).
 *
 * Return the *maximum* number of enemy forts you can capture. If it is impossible to capture any, return 0.
 *
 * Constraints
 * - 1 <= forts.length <= 1000
 * - forts[i] is either -1, 0, or 1.
 *
 * Examples
 *
 * Example 1:
 * - Input: forts = [1, 0, 0, -1, 0, 0, 0, 0, 1]
 * - Output: 4
 * - Explanation:
 *   - Moving from index 0 to index 3 captures 2 enemy forts.
 *   - Moving from index 8 to index 3 captures 4 enemy forts.
 *   - The maximum captured is 4.
 *
 * Example 2:
 * - Input: forts = [0, 1, -1, 0]
 * - Output: 0
 * - Explanation: No enemy forts can be captured since there are no enemy forts between a fort under your command and an empty gate.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.util.Scanner;

public class Q2_MaximumEnemyFortsThatCanBeCaptured {
     public int range(int[] forts){
        int ans = 0;
        int n = forts.length;
        int i = 0;
        while(i < n){
            if(forts[i] == 1){
                int j = i+1;
                int currentLen = 0;
                while(j < n && forts[j] == 0){
                    currentLen++;
                    j++;
                };
                if(j < n && forts[j] == -1){
                    ans = Math.max(ans,currentLen);
                }
            }
            i++;
        }

        return ans;
    }
    public int captureForts(int[] forts) {
        int ans = range(forts);
        ans = Math.max(ans,range(getReversed(forts)));
        return ans;

       

       
    }
    public static int[] getReversed(int[] arr) {
        int[] reversed = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            reversed[i] = arr[arr.length - 1 - i];
        }
        return reversed;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        int[] forts = new int[n];
        for (int i = 0; i < n; i++) {
            forts[i] = scanner.nextInt();
        }
        Q2_MaximumEnemyFortsThatCanBeCaptured solver = new Q2_MaximumEnemyFortsThatCanBeCaptured();
        System.out.println(solver.captureForts(forts));
    }
}
