/*
 * ============================================================================
 *  Daily Assignment - 13/Oct/2026
 *  Question 1 of 2: Total XOR Sum of All Subarrays
 *  Platform: geek101.dev
 *  Company: Adobe 2025
 *  Language: C++ (translated to Java below)
 *  Verdict: Accepted (8/8 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Problem Description
 *
 * Given an array of N integers, find the sum of the XOR sums of all its subarrays. Since the answer can be very large, return it modulo 10^9 + 7.
 *
 * A subarray is defined as a contiguous part of an array.
 * The XOR sum of a subarray is the bitwise XOR of all its elements.
 *
 * Input Format
 *
 * - The first line contains an integer N, the number of elements in the array.
 * - The second line contains N space-separated integers representing the elements of the array.
 *
 * Output Format
 *
 * - Print a single integer representing the sum of XOR sums of all subarrays modulo 10^9 + 7.
 *
 * Constraints
 *
 * - 1 <= N <= 10^5
 * - 0 <= A[i] <= 10^9
 *
 * Examples
 *
 * Example 1
 * Input:
 *
 * 3
 * 1 2 3
 *
 * Output:
 *
 * 10
 *
 * Explanation:
 * The subarrays and their XOR sums are:
 * - [1] -> 1
 * - [2] -> 2
 * - [3] -> 3
 * - [1, 2] -> 1 ^ 2 = 3
 * - [2, 3] -> 2 ^ 3 = 1
 * - [1, 2, 3] -> 1 ^ 2 ^ 3 = 0
 *
 * The total sum of XOR sums is 1 + 2 + 3 + 3 + 1 + 0 = 10.
 *
 * Example 2
 * Input:
 *
 * 4
 * 5 9 7 6
 *
 * Output:
 *
 * 86
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.io.*;
import java.util.*;

public class Q1_TotalXORSumOfAllSubarrays {
    static final long MOD = 1_000_000_007L;

    static long solve(int n, int[] a) {
        long ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            long count = 0;

            // Number of subarrays where this bit contributes 1
            long prefixParity = 0;
            long even = 1, odd = 0;

            for (int i = 0; i < n; i++) {
                prefixParity ^= (a[i] >> bit) & 1;

                if (prefixParity == 0) {
                    count += odd;
                    even++;
                } else {
                    count += even;
                    odd++;
                }
            }

            long contribution = (count % MOD * (1L << bit)) % MOD;
            ans = (ans + contribution) % MOD;
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;

        int n = Integer.parseInt(line.trim());
        int[] a = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        System.out.println(solve(n, a));
    }
}


/*
 * ============================================================================
 *  ORIGINAL C++ SUBMISSION (exactly as submitted on geek101.dev)
 * ============================================================================
 *  #include <iostream>
 *  #include <vector>
 *
 *  using namespace std;
 *
 *  const long long MOD = 1e9 + 7;
 *
 *  int solve(int n, const vector<int>& a) {
 *    long long ans = 0;
 *
 *      for (int bit = 0; bit < 31; bit++) {
 *          long long count = 0;
 *
 *          // Number of subarrays where this bit contributes 1
 *          long long prefixParity = 0;
 *          long long even = 1, odd = 0;
 *
 *          for (int i = 0; i < n; i++) {
 *              prefixParity ^= (a[i] >> bit) & 1;
 *
 *              if (prefixParity == 0) {
 *                  count += odd;
 *                  even++;
 *              } else {
 *                  count += even;
 *                  odd++;
 *              }
 *          }
 *
 *          long long contribution = (count % MOD * (1LL << bit)) % MOD;
 *          ans = (ans + contribution) % MOD;
 *      }
 *
 *      return ans;
 *  }
 *
 *  int main() {
 *      ios_base::sync_with_stdio(false);
 *      cin.tie(NULL);
 *      int n;
 *      if (cin >> n) {
 *          vector<int> a(n);
 *          for (int i = 0; i < n; i++) {
 *              cin >> a[i];
 *          }
 *          cout << solve(n, a) << "\n";
 *      }
 *      return 0;
 *  }
 */
