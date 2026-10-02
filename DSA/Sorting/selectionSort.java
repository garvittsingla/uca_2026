    package Sorting;
    
    import java.util.Arrays;
    /*
        Selection Sort Algorithm
        Sorting algorithm that repeatedly selects the minimum element from the unsorted portion and places it at the beginning.
        Time Complexity->
            Worst Case: O(n^2)
            Best Case: O(n^2)
            Average Case: O(n^2)
        Space Complexity: O(1) (In-Place)
        Cache Affinity : Good
        IsStable : No
        Maximum Swaps = n-1
        
    */
    
    public class selectionSort{
        public static void sort(int[] arr){
            int swaps = 0;
            for(int i = 0 ; i < arr.length ; i++){
                int miniindex = i;
                for(int j = i+1 ; j < arr.length ; j++){
                    if(arr[j] < arr[miniindex]) miniindex = j;
                }
                if(miniindex != i){
                    swaps++;
                    int temp = arr[i];
                    arr[i] = arr[miniindex];
                    arr[miniindex] = temp;
                }
            }
            System.out.println("Swaps: " + swaps);
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