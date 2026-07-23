#include "iostream"
#include <vector>


void merge(std::vector<int> &arr,int low,int mid,int high){
    int left = low;
    int right= mid+1;
    std::vector<int> temp(high-low+1);

    int k = 0;
    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp[k++] = arr[left++];
        }else{
            temp[k++] = arr[right++];
        }
    }

    while(left<=mid){
        temp[k++] = arr[left++];
    }
    while(right <= high){
        temp[k++] = arr[right++];
    }

    k = 0;
    for(int i = low ; i <= high ; i++){
        arr[i] = temp[k++];
    }


}
int countPairs(std::vector<int> &arr,int low,int mid,int high){
    int right = mid+1;
    int count = 0;

    for(int i = low ; i <= mid; i++){
        while(right <= high && arr[i] > (2*arr[right])) right++;
        count += (right-(mid+1));
    }
    return count;
}

int mergeSort(std::vector<int> &arr,int low,int high){
    if(low >= high) return 0;
    int mid = low+(high-low)/2;

    int l = mergeSort(arr,low,mid);
    int r = mergeSort(arr,mid+1,high);
    int c = countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return l+r+c;

}
int main(){
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) std::cin >> arr[i];
    
    std::cout << mergeSort(arr,0,n-1) << std::endl;

   

}