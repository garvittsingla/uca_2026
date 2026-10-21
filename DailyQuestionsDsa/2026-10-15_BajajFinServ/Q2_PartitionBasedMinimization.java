/*
 * ============================================================================
 *  Daily Assignment - 15/Oct/2026
 *  Question 2 of 2: Partition-Based Minimization
 *  Platform: geek101.dev
 *  Company: Bajaj FinServ 2025
 *  Language: Java
 *  Verdict: Accepted (10/10 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Problem Description
 *
 * You are given a string S consisting of lowercase English letters. You must partition the string into consecutive sections such that:
 * 1. Each character in S appears in exactly one section.
 * 2. No character appears in more than one section. (For example, if the character 'a' is in the first section, it cannot appear in any other section).
 *
 * The score of a section is defined as the square of its length: (length of section)^2. Your goal is to find a valid partition that minimizes the total score (the sum of the scores of all sections).
 *
 * Input Format
 * - A single string S consisting of lowercase English letters.
 *
 * Output Format
 * - Return the minimum total score as a 64-bit integer.
 *
 * Constraints
 * - 1 <= |S| <= 10^6
 * - S consists only of lowercase English letters ('a' - 'z').
 *
 * Examples
 *
 * Example 1:
 * - Input: abacd
 * - Output: 11
 * - Explanation: We can partition the string into "aba", "c", and "d".
 *   - Section "aba" has length 3, score 3^2 = 9.
 *   - Section "c" has length 1, score 1^2 = 1.
 *   - Section "d" has length 1, score 1^2 = 1.
 *   - Total score = 9 + 1 + 1 = 11.
 *   - This is valid because 'a' and 'b' only appear in the first section, 'c' only in the second, and 'd' only in the third.
 *
 * Example 2:
 * - Input: abacaba
 * - Output: 49
 * - Explanation: Since 'a' appears at the very beginning and the very end, the entire string must be in a single section.
 *   - Section "abacaba" has length 7, score 7^2 = 49.
 *
 * ---
 * Implement the function min_partition_score (or equivalent in your language). You only need to implement this function; the starter code handles reading the input and printing the output.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Q2_PartitionBasedMinimization {
    public static long minPartitionScore(String s) {
        int n = s.length();
      int[] last = new int[26];
      for(int i = 0 ; i < n ; i++){
        last[s.charAt(i) - 'a'] = i;
      }

      long ans = 0;
      int start = 0;
      int end = 0;

      for(int i = 0 ; i < n ; i++){
         end = Math.max(end, last[s.charAt(i) - 'a']);
        if (i == end) {
            long len = i - start + 1;
            ans += len * len;

            start = i + 1;
        }
        
      }
      return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s = reader.readLine();
        if (s != null) {
            s = s.trim();
            if (!s.isEmpty()) {
                System.out.println(minPartitionScore(s));
            }
        }
    }
}
