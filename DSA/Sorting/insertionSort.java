package Sorting;

import java.util.Arrays;
/*
    Insertion Sort Algorithm
    A simple comparison-based sorting algorithm. starting from a index and places a element at its correct
    position by comparing it with the elements before it.
    Time Complexity->
        Worst Case: O(n^2)
        Best Case: O(n)
        Average Case: O(n^2)
    Space Complexity: O(1) (In-Place)
    Cache Affinity : Very good
    IsStable : Yes
    
*/

public class insertionSort{
    public static void sort(int[] arr){
        int iterations = 0;
        for(int i = 0 ; i < arr.length ; i++){
            for(int j = i-1; j>=0; j--){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    iterations++;
                }else{
                    break;
                }
            }
        }
        System.out.println("Iterations: " + iterations);
    }
    public static void main(String[] args) {
        int[] arr = {4,1,44,65,3};

        sort(arr);

        int[] arr2 = {1,2,3,4,5};
        sort(arr2);
        
        System.out.println(Arrays.toString(arr));
        
    }
}