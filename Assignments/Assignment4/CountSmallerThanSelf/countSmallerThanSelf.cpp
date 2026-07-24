#include "iostream"
#include "vector"

using namespace std;
void merge(vector<pair<int,int>>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<pair<int,int>> temp(high - low + 1);
    int k = 0;

    while (left <= mid && right <= high) {
        if (arr[left].first <= arr[right].first) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid)
        temp[k++] = arr[left++];

    while (right <= high)
        temp[k++] = arr[right++];

    k = 0;
    for (int i = low; i <= high; i++)
        arr[i] = temp[k++];
}

void count(vector<pair<int,int>>& arr, int low, int mid, int high,vector<int>&ans) {
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[right].first < arr[i].first)
            right++;

        ans[arr[i].second] += (right - (mid + 1));
    }
}

void mergeSort(vector<pair<int,int>>& arr, int low, int high,vector<int> &ans) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid,ans);
    mergeSort(arr, mid + 1, high,ans);

    count(arr, low, mid, high,ans);   
    merge(arr, low, mid, high);
}
int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> ans(n,0);
    for(int i = 0 ; i < n ; i++) cin >> nums[i];

    vector<pair<int,int>> arr;
    for(int i = 0 ; i < n ; i++){
        arr.push_back({nums[i],i});
    }

    mergeSort(arr,0,n-1,ans);

    for(auto it:ans){
        cout << it << " ";
    }
    cout << endl;
}