#include "iostream"
#include <vector>
#include <utility>

class MaxHeap{
    protected:
        std::vector<int> list;

        bool isEmpty(){
            return list.size() == 0;
        }
        int parent(int index){
            return (index-1)/2; //0 based indexing , otherwise it would be index/2
        } 
        int left(int index){
            return (2*index)+1;  //0 based indexing , otherwise it would be 2*index only
        }
        int right(int index){
            return (2*index)+2; //0 based indexing , otherwise it would be 2*index+1 only
        }
        void goUp(int index){
            if(index == 0) return;

            int p = parent(index);

            if(list[p] < list[index]){
                std::swap(list[p],list[index]);
                goUp(p);
            }

        }

        void goDown(int index){
            int largest = index;
            int l = left(index);
            int r = right(index);
            if(l < list.size() && list[l] > list[largest]){
                largest = l;
            }

            if(r < list.size() && list[r] > list[largest]){
                largest = r;
            }

            if(index  == largest) return ;
            std::swap(list[largest],list[index]);

            goDown(largest);
        }

    public:
        MaxHeap(int size){
            list.reserve(size);
        } 
        //O(log n)
        void insert(int element){
            list.push_back(element);
            //we have to place it to its right position
            goUp(list.size()-1);
        }
        // O(1)
        int getMax(){
            if(isEmpty()) return -1;
            return list[0];
        }
        // O(log n)
        int remove(){
            int largest = getMax();
            std::swap(list[0], list[list.size() - 1]);
            list.pop_back();
            if (!list.empty()) {
                goDown(0);
            }
            return largest;
        }



};

class HeapifyCustomArray : public MaxHeap{
    public:
        HeapifyCustomArray(std::vector<int> arr) : MaxHeap(arr.size()){
            list = arr;
            for (int i = list.size() / 2 - 1; i >= 0; i--) { // non leaf nodes, compare and make it in O(n)
                goDown(i);
            }
        }
        
};

int main(){
    std::vector<int> arr = {32,43,54,5,457,3,32,23,43};

    // MaxHeap hp(9);
    // for(auto it:arr){
    //     hp.insert(it);
    // }

    // for(int i = 0 ; i < 9 ; i ++){
    //     std::cout << hp.remove() << std::endl;
    // }

    HeapifyCustomArray hp(arr);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << hp.remove() << std::endl;
    }

}