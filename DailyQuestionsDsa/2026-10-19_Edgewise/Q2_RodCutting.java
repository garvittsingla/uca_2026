/*
 * ============================================================================
 *  Daily Assignment - 19/Oct/2026
 *  Question 2 of 2: Rod Cutting
 *  Platform: geek101.dev
 *  Company: Edgewise 2025
 *  Language: Java
 *  Verdict: Accepted (8/8 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Given a rod of length n and an array of prices, where prices[i] represents the price of a rod piece of length i + 1, determine the maximum value obtainable by cutting up the rod and selling the pieces. You can make as many cuts as you want, or no cuts at all.
 *
 * Constraints
 * - 1 <= n <= 1000
 * - 1 <= prices[i] <= 10^5
 *
 * Examples
 *
 * Example 1
 * Input:
 *
 * n = 8
 * prices = [1, 5, 8, 9, 10, 17, 17, 20]
 *
 * Output: 22
 *
 * Explanation: The maximum value is obtained by cutting the rod into two pieces of lengths 2 and 6. The total value is prices[1] + prices[5] = 5 + 17 = 22.
 *
 * Example 2
 * Input:
 *
 * n = 8
 * prices = [3, 5, 8, 9, 10, 17, 17, 20]
 *
 * Output: 24
 *
 * Explanation: The maximum value is obtained by cutting the rod into 8 pieces of length 1. The total value is 8 * prices[0] = 8 * 3 = 24.
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.util.Scanner;
import java.util.*;

public class Q2_RodCutting {
    public static int helper(int[] price,int lengthleft,int index,int[][] dp){
        if(lengthleft == 0) return 0;
        if(index >= price.length) return 0;
        
        if(dp[lengthleft][index]!=-1) return dp[lengthleft][index];
        int nottake =  helper(price,lengthleft,index+1,dp);
        
        int take = Integer.MIN_VALUE;
        
        for(int i = index ; i < price.length ; i++){
            if( (i+1)> lengthleft) break;
            int value = price[i] + helper(price,lengthleft-(i+1),i,dp);
            take = Math.max(take,value);
        }
        
        return dp[lengthleft][index] = Math.max(take,nottake);
    }
    public static int maxRodValue(int n, int[] price) {
       int[][] dp = new int[price.length+1][price.length + 1];
       for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return helper(price,price.length,0,dp);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] prices = new int[n];
            for (int i = 0; i < n; i++) {
                prices[i] = scanner.nextInt();
            }
            System.out.println(maxRodValue(n, prices));
        }
        scanner.close();
    }
}
