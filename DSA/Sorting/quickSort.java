    package Sorting;
    
    import java.util.Arrays;
    /*
        Quick Sort Algorithm
        Algorithm in which we choose a pivot and place elements smaller than it before it and greater elemnts after it , making the pivot come in its correct sorted position.
        Time Complexity->
            Worst Case:  O(n^2)
            Best Case:  O(n log n)
            Average Case: O(n log n)
        Space Complexity: O(1) (In-Place)
        Cache Affinity : Good
        IsStable : no
        
    */
    
    public class quickSort{
        
        public static void sort(int[] arr,int low,int high){
            if (low >= high) return;

            int pivotindex = partition(arr,low,high);
            sort(arr,low,pivotindex-1);
            sort(arr,pivotindex+1,high);
        }
        public static int partition(int[] arr,int low,int high){
            int pivot = arr[high];
            int i = low-1;
            for(int j = low; j < high; j++){
                if(arr[j] < pivot){
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            int temp = arr[i+1];
            arr[i+1] = arr[high];
            arr[high] = temp;
            return i+1;
        }
        public static void main(String[] args) {
            int[] arr = {4,1,44,65,3};
            sort(arr,0,arr.length-1);
            int[] arr2 = {1,2,3,4,5};
            sort(arr2,0,arr2.length-1);
            
            System.out.println(Arrays.toString(arr));
            System.out.println(Arrays.toString(arr2));
            
        }
    }