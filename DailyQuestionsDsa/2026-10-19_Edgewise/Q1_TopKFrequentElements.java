/*
 * ============================================================================
 *  Daily Assignment - 19/Oct/2026
 *  Question 1 of 2: Top K Frequent Elements
 *  Platform: geek101.dev
 *  Company: Edgewise 2025
 *  Language: Java
 *  Verdict: Accepted (7/7 test cases passed)
 * ============================================================================
 *
 *  PROBLEM STATEMENT
 *  -----------------
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 *
 * Constraints
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * - k is in the range [1, number of unique elements in the array].
 * - It is guaranteed that the answer is unique (i.e., the set of k most frequent elements is unique).
 *
 * Examples
 *
 * Example 1:
 * - Input: nums = [1, 1, 1, 2, 2, 3], k = 2
 * - Output: [1, 2] (or [2, 1])
 *
 * Example 2:
 * - Input: nums = [1], k = 1
 * - Output: [1]
 *
 * ============================================================================
 *  MY SOLUTION
 * ============================================================================
 */
import java.util.*;

public class Q1_TopKFrequentElements {
   static class Pair{
        public int a,b;
        Pair(int a,int b){
            this.a = a;
            this.b = b;
        }
    }
    public static int[] topKFrequent(int[] nums, int k) {
       PriorityQueue<Pair> pq = new PriorityQueue<>((x,y)->{
        return Integer.compare(y.b,x.b);
       });

       HashMap<Integer,Integer> map = new HashMap<>();
       for(Integer it:nums){
            int value = map.getOrDefault(it,0);
            map.put(it,value+1);
       }

       for(Map.Entry<Integer,Integer> it:map.entrySet()){
        int key = it.getKey();
        int value = it.getValue();

        pq.add(new Pair(key,value));
       }

        int[] ans = new int[k];
        int i = 0;
        while(k!=0){
            int ele = pq.peek().a;
            pq.poll();
            ans[i++]  = ele;
            k--;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int[] result = topKFrequent(nums, k);
        Arrays.sort(result);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + (i == result.length - 1 ? "" : " "));
        }
        System.out.println();
    }
}
