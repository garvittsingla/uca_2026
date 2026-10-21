/*
 * ============================================================================
 *  Daily Assignment - 20/Oct/2026
 *  Question 2 of 2: Match Game Sequences
 *  Platform: geek101.dev
 *  Company: Playsimple 2025
 *  Language: Java
 *  Verdict: Accepted (7/7 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * You are given N game sequences, each of length M, and Q queries, each also of length M.
 *
 * Each query contains integers, where the value -1 indicates that the remaining elements of the query should be ignored. For each query, we only consider the prefix of values before the first occurrence of -1. If there is no -1 in the query, the entire query of length M is considered.
 *
 * A game sequence is said to match a query if the game sequence's prefix of the same length exactly matches the query's valid prefix.
 *
 * Your task is to determine, for each query, how many game sequences match it.
 *
 * Constraints
 * - 1 <= N <= 500
 * - 1 <= M <= 50
 * - 1 <= Q <= 500
 * - Game sequence elements are positive integers between 1 and 10^9.
 * - Query elements are either positive integers between 1 and 10^9, or -1.
 *
 * Example 1
 *
 * Input:
 * - N = 3, M = 4
 * - games =
 *
 *   [[1, 2, 3, 4],
 *    [1, 2, 5, 6],
 *    [2, 3, 4, 5]]
 *
 * - Q = 3
 * - queries =
 *
 *   [[1, 2, -1, -1],
 *    [1, 2, 3, -1],
 *    [2, -1, -1, -1]]
 *
 * Output:
 * [2, 1, 1]
 *
 * Explanation:
 * - Query 1: The valid prefix is [1, 2]. The game sequences starting with [1, 2] are [1, 2, 3, 4] and [1, 2, 5, 6]. Total matches = 2.
 * - Query 2: The valid prefix is [1, 2, 3]. The only game sequence starting with [1, 2, 3] is [1, 2, 3, 4]. Total matches = 1.
 * - Query 3: The valid prefix is [2]. Only [2, 3, 4, 5] starts with 2. Total matches = 1.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Q2_MatchGameSequences {
    public static List<Integer> countMatchingSequences(int n, int m, List<List<Integer>> games, int q, List<List<Integer>> queries) {
        
        List<Integer> ans = new ArrayList<>();
        
        for(int i  = 0 ; i < q ; i++){
            List<Integer> query = queries.get(i);
            
            int num = 0;
            for(int j = 0 ; j < m ; j++){
                if(query.get(j) == -1) break;
                num++;
            }
            
            
            int matches = 0;
            for(int j = 0 ; j < n ; j++){
                boolean isMatch = true;
                for (int k = 0; k < num; k++) {
                    if (!query.get(k).equals(games.get(j).get(k))) {
                        isMatch = false;
                        break;
                    }
                }

                
                if(isMatch) matches++;
                
            }
            
            ans.add(matches);
        }
        return ans;

        
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        List<List<Integer>> games = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < M; j++) {
                row.add(sc.nextInt());
            }
            games.add(row);
        }
        
        if (!sc.hasNextInt()) return;
        int Q = sc.nextInt();
        
        List<List<Integer>> queries = new ArrayList<>();
        for (int i = 0; i < Q; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < M; j++) {
                row.add(sc.nextInt());
            }
            queries.add(row);
        }
        
        List<Integer> result = countMatchingSequences(N, M, games, Q, queries);
        for (int val : result) {
            System.out.println(val);
        }
    }
}
