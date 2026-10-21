/*
 * ============================================================================
 *  Daily Assignment - 20/Oct/2026
 *  Question 1 of 2: Closest Word by Edit Distance
 *  Platform: geek101.dev
 *  Company: Playsimple 2025
 *  Language: Java
 *  Verdict: Accepted (8/8 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * You are given an integer N representing the number of words, an array of N strings words, and a target string S.
 *
 * For each word in the array, compute the Levenshtein (Edit) Distance between that word and the string S. The edit distance is defined as the minimum number of operations required to convert one string into another, where the allowed operations are:
 * 1. Insert a character
 * 2. Delete a character
 * 3. Replace a character
 *
 * Your task is to return the word from the array that has the minimum edit distance with S. If more than one word has the same minimum edit distance, return the lexicographically smallest word among them.
 *
 * Constraints
 * - 1 <= N <= 100
 * - 1 <= length of each word <= 100
 * - 1 <= length of  S <= 100
 * - All strings consist of lowercase English letters only.
 *
 * Examples
 *
 * Example 1
 * Input:
 *
 * 4
 * car bat cats dog
 * cat
 *
 * Output:
 * bat
 *
 * Explanation:
 * - Edit distance between "car" and "cat" is 1 (replace 'r' with 't').
 * - Edit distance between "bat" and "cat" is 1 (replace 'b' with 'c').
 * - Edit distance between "cats" and "cat" is 1 (delete 's').
 * - Edit distance between "dog" and "cat" is 3.
 * The minimum edit distance is 1. The candidates are "car", "bat", and "cats". Among these, "bat" is lexicographically the smallest.
 *
 * Example 2
 * Input:
 *
 * 4
 * apply apples ape bapple
 * apple
 *
 * Output:
 * apples
 *
 * Explanation:
 * - "apply" to "apple": 1 (replace 'y' with 'e')
 * - "apples" to "apple": 1 (delete 's')
 * - "ape" to "apple": 2 (insert 'p', 'l')
 * - "bapple" to "apple": 1 (delete 'b')
 * The minimum edit distance is 1. The candidates are "apply", "apples", and "bapple". Among these, "apples" is lexicographically the smallest.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.util.*;

public class Q1_ClosestWordByEditDistance {
   public static int helper(String word1,String word2,int i,int j,int[][] dp){
        if(j >= word2.length()){
            return word1.length() - i;
        }

        if(i >= word1.length()){
            return word2.length() - j;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        char ch1 = word1.charAt(i);
        char ch2 = word2.charAt(j);

        if(ch1 == ch2) return helper(word1,word2,i+1,j+1,dp);
        
        int delete = 1 + helper(word1,word2,i+1,j,dp);
        int replace = 1 + helper(word1,word2,i+1,j+1,dp);
        int insert = 1 + helper(word1, word2, i, j + 1,dp);

        return dp[i][j] = Math.min(delete,Math.min(replace,insert));

    }
    public static String findClosestWord(int n, String[] words, String s) {
        String answer = "";
        int minDistance = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int[][] dp = new int[words[i].length()][s.length()];

            for (int[] row : dp) {
                Arrays.fill(row, -1);
            }

            int distance = helper(words[i], s, 0, 0, dp);

            if (distance < minDistance ||
                (distance == minDistance &&
                 words[i].compareTo(answer) < 0)) {

                minDistance = distance;
                answer = words[i];
            }
        }

        return answer;
    }

    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = sc.next();
        }
        String s = sc.next();
        System.out.println(findClosestWord(n, words, s));
    }
}
