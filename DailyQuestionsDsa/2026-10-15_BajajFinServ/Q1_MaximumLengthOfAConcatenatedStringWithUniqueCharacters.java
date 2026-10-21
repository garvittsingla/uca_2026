/*
 * ============================================================================
 *  Daily Assignment - 15/Oct/2026
 *  Question 1 of 2: Maximum Length of a Concatenated String with Unique Characters
 *  Platform: geek101.dev
 *  Company: Bajaj FinServ 2025
 *  Language: Java
 *  Verdict: Accepted (9/9 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Problem Description
 *
 * Given an array of strings arr, find the maximum length of a string formed by the concatenation of a subsequence of arr that has unique characters.
 *
 * A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 *
 * Constraints
 *
 * - 1 <= arr.length <= 16
 * - 1 <= arr[i].length <= 26
 * - arr[i] contains only lowercase English letters.
 *
 * Examples
 *
 * Example 1
 * Input:
 *
 * 3
 * un
 * iq
 * ue
 *
 * Output:
 *
 * 4
 *
 * Explanation: All possible concatenations are:
 * - "" (length 0)
 * - "un" (length 2)
 * - "iq" (length 2)
 * - "ue" (length 2)
 * - "uniq" ("un" + "iq", length 4)
 * - "unique" ("un" + "iq" + "ue", invalid because 'u' and 'e' are repeated)
 * - "ique" ("iq" + "ue", length 4)
 * - "unue" ("un" + "ue", invalid because 'u' is repeated)
 * The maximum length is 4.
 *
 * Example 2
 * Input:
 *
 * 4
 * cha
 * r
 * act
 * ers
 *
 * Output:
 *
 * 6
 *
 * Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers"). Both have length 6.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.util.*;
import java.io.*;

public class Q1_MaximumLengthOfAConcatenatedStringWithUniqueCharacters {
    // TODO: Implement the maxLength function
    public static int helper(List<String> arr,int index,StringBuilder sb){
        int maxLen = sb.length();
        if(index >= arr.size()){
            return maxLen;
        }

        boolean canAdd = true;
        boolean[] seen = new boolean[26];
        for(int i = 0; i < arr.get(index).length() ; i++){
            if (sb.indexOf(String.valueOf(arr.get(index).charAt(i))) != -1){
                canAdd = false;
                break;
            }

            Character ch = arr.get(index).charAt(i);
            int c = ch - 'a';

            if(seen[c]){
                canAdd = false;
                break;
            }

            seen[c] = true;
        }

        if(canAdd){
            int originalLength = sb.length();
            sb.append(arr.get(index));
            maxLen = Math.max(maxLen, helper(arr, index + 1, sb));
            sb.setLength(originalLength);
        }

        maxLen = Math.max(maxLen,helper(arr,index+1,sb));

        return maxLen;

    }
    public static int maxLength(List<String> arr) {
       StringBuilder sb = new StringBuilder();
        return helper(arr,0,sb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        if (line == null || line.trim().isEmpty()) return;
        int n = Integer.parseInt(line.trim());
        List<String> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = reader.readLine();
            if (s != null) {
                arr.add(s.trim());
            }
        }
        System.out.println(maxLength(arr));
    }
}
