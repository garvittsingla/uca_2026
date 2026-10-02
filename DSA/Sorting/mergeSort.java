    package Sorting;
    
    import java.util.Arrays;
    /*
        Merge Sort Algorithm
        Algorithms which follow divide and conquer approach, dividing the array into smaller subarrays and merging them in sorted order.
        Time Complexity->
            Worst Case:  O(n log n)
            Best Case:  O(n log n)
            Average Case: O(n log n)
        Space Complexity: O(n) (Not In-Place)
        Cache Affinity : Good
        IsStable : Yes
        
    */
    
    public class mergeSort{
        public static void merge(int[] arr,int left,int mid,int right){
            if(left >= right) return;
            int temp[] = new int[right-left+1];
            int i = left;
            int j = mid+1;
            int k = 0;
            while(i <= mid && j <= right){
               if(arr[i] < arr[j]){
                   temp[k++] = arr[i++];
               }else{
                   temp[k++] = arr[j++];
               }
            }
            while(i <= mid){
                temp[k++] = arr[i++];
            }
            while(j <= right){
                temp[k++] = arr[j++];
            }
            k = 0;
            for(int t = left; t < right+1; t++){
                arr[t] = temp[k++];
            }
        }
        public static void sort(int[] arr,int left,int right){
            if(left >= right) return;

            int mid = left+(right-left)/2;
            sort(arr,left,mid);
            sort(arr,mid+1,right);
            merge(arr,left,mid,right);
            
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