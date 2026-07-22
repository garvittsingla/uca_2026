#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int longestConsectiveSequence(std::vector<int> &arr){
    int n = arr.size();

    int ans = 0;

    std::unordered_set<int> st(arr.begin(),arr.end());

    for(auto it:st){
        if(!st.count(it-1)){
            int currentCount = 1;
            int currentNumber = it;
            while(st.count(currentNumber+1)){
                currentCount++;
                currentNumber = currentNumber+1;
            }

            ans = std::max(currentCount,ans);
        }
    }

    return ans;

}

int main(){
    int size;
    std::cin >> size;

    std::vector<int> arr(size,0);

    for(int i = 0 ; i < size ; i++){
        std::cin >> arr[i];
    }

    std::cout << "The length of the longest sequence is : " << longestConsectiveSequence(arr) << std::endl;


}

