/*
 * ============================================================================
 *  Daily Assignment - 14/Oct/2026
 *  Question 2 of 2: Number of Excellent Pairs
 *  Platform: geek101.dev
 *  Company: ServiceNow 2025
 *  Language: Java
 *  Verdict: Accepted (8/8 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Problem Description
 *
 * You are given a 0-indexed array of positive integers nums and a positive integer k.
 *
 * A pair of numbers (num1, num2) is called excellent if the following conditions are satisfied:
 * 1. Both num1 and num2 exist in the array nums (i.e., they are part of the set of unique elements in nums).
 * 2. The sum of the number of set bits in (num1 OR num2) and (num1 AND num2) is greater than or equal to k.
 *
 * Return the number of distinct excellent pairs.
 *
 * Note that:
 * - Two pairs (num1, num2) and (num2, num1) are considered different if num1 != num2.
 * - The numbers in the pair must exist in nums. This means we only consider the unique elements of nums to form pairs.
 *
 * Bitwise Identity Hint
 * For any two integers A and B, the sum of the set bits in (A  OR  B) and (A  AND  B) is equal to the sum of the set bits in A and B:
 * popcount(A  OR  B) + popcount(A  AND  B) = popcount(A) + popcount(B)
 *
 * Input Format
 * - The first line contains an integer N, the number of elements in nums.
 * - The second line contains N space-separated integers representing the elements of nums.
 * - The third line contains an integer k.
 *
 * Output Format
 * - Print a single integer representing the number of excellent pairs.
 *
 * Constraints
 * - 1 <= N <= 10^5
 * - 1 <= nums[i] <= 10^9
 * - 1 <= k <= 60
 *
 * Examples
 *
 * Example 1:
 * Input:
 *
 * 4
 * 1 2 3 1
 * 3
 *
 * Output:
 *
 * 5
 *
 * Explanation:
 * The unique elements in nums are [1, 2, 3].
 * The excellent pairs and their set bits sum are:
 * - (1, 3): popcount(1) + popcount(3) = 1 + 2 = 3 >= 3
 * - (2, 3): popcount(2) + popcount(3) = 1 + 2 = 3 >= 3
 * - (3, 1): popcount(3) + popcount(1) = 2 + 1 = 3 >= 3
 * - (3, 2): popcount(3) + popcount(2) = 2 + 1 = 3 >= 3
 * - (3, 3): popcount(3) + popcount(3) = 2 + 2 = 4 >= 3
 * There are 5 excellent pairs.
 *
 * Example 2:
 * Input:
 *
 * 5
 * 5 1 1 1 2
 * 1
 *
 * Output:
 *
 * 9
 *
 * Explanation:
 * The unique elements are [5, 1, 2]. Since every unique element has at least 1 set bit, any pair of these elements will have a sum of set bits >= 2 >= 1. Thus, all 3 x 3 = 9 pairs are excellent.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.io.*;
import java.util.*;

public class Q2_NumberOfExcellentPairs {
    public static long countExcellentPairs(int[] nums, int k) {
        HashSet<Integer> st = new HashSet<>();
        for (int num : nums) {
            st.add(num);
        }

        int[] uniques = new int[st.size()];
        int i = 0;

        for (Integer it : st) {
           int count = Integer.bitCount(it);
           uniques[i++] = count;
        }

       long ans = 0;
        for(i = 0 ; i < uniques.length ; i++){
          for(int j = 0 ; j < uniques.length ; j++){
            if(uniques[i] + uniques[j] >= k) ans++;
          }
        }
      return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        int n = Integer.parseInt(line.trim());
        int[] nums = new int[n];
        String[] parts = br.readLine().trim().split("\\s+");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(parts[i]);
        }
        int k = Integer.parseInt(br.readLine().trim());
        System.out.println(countExcellentPairs(nums, k));
    }
}
