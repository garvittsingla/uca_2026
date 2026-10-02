    package Sorting;
    
    import java.util.Arrays;
    /*
        Bubble Sort Algorithm
        Sorting algorithm that repeatedly swaps adjacent elements if they are in the wrong order and starts placing from the back of the array
        Time Complexity->
            Worst Case: O(n^2)
            Best Case: O(n)
            Average Case: O(n^2)
        Space Complexity: O(1) (In-Place)
        Cache Affinity : Very Good
        IsStable : Yes
        Maximum Swaps = n(n-1)/2
        
    */
    
    public class bubbleSort{
        public static void sort(int[] arr){
            for(int i = 0 ; i < arr.length-1 ; i++){
                boolean swapped = false;
                for(int j = 0 ; j < arr.length-i-1 ; j++){
                    if(arr[j] > arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                        swapped = true;
                    }
                }
                if(!swapped) break;
            }
        }
        public static void main(String[] args) {
            int[] arr = {4,1,44,65,3};
            sort(arr);
            int[] arr2 = {1,2,3,4,5};
            sort(arr2);
            
            System.out.println(Arrays.toString(arr));
            System.out.println(Arrays.toString(arr2));
            
        }
    }