/*
 * ============================================================================
 *  Daily Assignment - 13/Oct/2026
 *  Question 2 of 2: Longest Subsequence with Non-Zero Bitwise AND
 *  Platform: geek101.dev
 *  Company: Adobe 2025
 *  Language: C++ (translated to Java below)
 *  Verdict: Accepted (8/8 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Given an array of N positive integers, find the length of the longest subsequence such that the bitwise AND of all elements in the subsequence is strictly greater than zero.
 *
 * A subsequence is a sequence that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 *
 * Input Format
 * - The first line contains an integer N, the number of elements in the array.
 * - The second line contains N space-separated integers representing the elements of the array.
 *
 * Output Format
 * - Print a single integer representing the maximum length of a subsequence with a bitwise AND strictly greater than zero.
 *
 * Constraints
 * - 1 <= N <= 10^5
 * - 1 <= A[i] <= 10^9
 *
 * Examples
 *
 * Example 1
 * Input:
 *
 * 7
 * 16 17 71 62 12 24 14
 *
 * Output:
 *
 * 4
 *
 * Explanation:
 * One possible subsequence is [71, 62, 12, 14]. Their bitwise AND is 71 & 62 & 12 & 14 = 4, which is strictly greater than zero.
 * Another possible subsequence is [16, 17, 62, 24] with bitwise AND 16 & 17 & 62 & 24 = 16 > 0.
 * The maximum length of such a subsequence is 4.
 *
 * Example 2
 * Input:
 *
 * 3
 * 8 8 8
 *
 * Output:
 *
 * 3
 *
 * Explanation:
 * The entire array [8, 8, 8] can be chosen. Their bitwise AND is 8 & 8 & 8 = 8 > 0.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.io.*;
import java.util.*;

public class Q2_LongestSubsequenceWithNonZeroBitwiseAnd {
    // Complete the function below
    static int largestSubsequence(int[] arr) {
        int ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            int cnt = 0;

            for (int x : arr) {
                if ((x & (1 << bit)) != 0) {
                    cnt++;
                }
            }

            ans = Math.max(ans, cnt);
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;

        int n = Integer.parseInt(line.trim());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        System.out.println(largestSubsequence(arr));
    }
}


/*
 * ============================================================================
 *  ORIGINAL C++ SUBMISSION (exactly as submitted on geek101.dev)
 * ============================================================================
 *  #include <iostream>
 *  #include <vector>
 *  #include <algorithm>
 *
 *  // Complete the function below
 *  int largestSubsequence(const std::vector<int>& arr) {
 *     int ans = 0;
 *
 *      for (int bit = 0; bit < 31; bit++) {
 *          int cnt = 0;
 *
 *          for (int x : arr) {
 *              if (x & (1LL << bit)) {
 *                  cnt++;
 *              }
 *          }
 *
 *          ans = std::max(ans, cnt);
 *      }
 *    return ans;
 *  }
 *
 *  int main() {
 *      std::ios_base::sync_with_stdio(false);
 *      std::cin.tie(NULL);
 *      int n;
 *      if (std::cin >> n) {
 *          std::vector<int> arr(n);
 *          for (int i = 0; i < n; ++i) {
 *              std::cin >> arr[i];
 *          }
 *          std::cout << largestSubsequence(arr) << "\n";
 *      }
 *      return 0;
 *  }
 */
