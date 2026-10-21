/*
 * ============================================================================
 *  Daily Assignment - 16/Oct/2026
 *  Question 1 of 2: Build Array from Permutation
 *  Platform: geek101.dev
 *  Company: FNP
 *  Language: Java
 *  Verdict: Accepted (7/7 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
 *
 * A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
 *
 * Constraints
 *
 * - 1 <= nums.length <= 1000
 * - 0 <= nums[i] < nums.length
 * - The elements in nums are distinct.
 *
 * Examples
 *
 * Example 1:
 * - Input: nums = [0, 2, 1, 5, 3, 4]
 * - Output: [0, 1, 2, 4, 5, 3]
 * - Explanation: The array ans is built as follows:
 *   - ans[0] = nums[nums[0]] = nums[0] = 0
 *   - ans[1] = nums[nums[1]] = nums[2] = 1
 *   - ans[2] = nums[nums[2]] = nums[1] = 2
 *   - ans[3] = nums[nums[3]] = nums[5] = 4
 *   - ans[4] = nums[nums[4]] = nums[3] = 5
 *   - ans[5] = nums[nums[5]] = nums[4] = 3
 *
 * Example 2:
 * - Input: nums = [5, 0, 1, 2, 3, 4]
 * - Output: [4, 5, 0, 1, 2, 3]
 * - Explanation: The array ans is built as follows:
 *   - ans[0] = nums[nums[0]] = nums[5] = 4
 *   - ans[1] = nums[nums[1]] = nums[0] = 5
 *   - ans[2] = nums[nums[2]] = nums[1] = 0
 *   - ans[3] = nums[nums[3]] = nums[2] = 1
 *   - ans[4] = nums[nums[4]] = nums[3] = 2
 *   - ans[5] = nums[nums[5]] = nums[4] = 3
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.util.Scanner;

public class Q1_BuildArrayFromPermutation {
    public static int[] buildArray(int[] nums) {
      int n = nums.length;
       int[] ans = new int[n];
       for(int i = 0 ; i < n ; i++){
            ans[i] = nums[nums[i]];
       }
       return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int[] ans = buildArray(nums);
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + (i == ans.length - 1 ? "" : " "));
        }
        System.out.println();
    }
}
