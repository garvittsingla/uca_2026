#include "iostream"
#include <algorithm>
#include <climits>

class Node{
    public:
    int val;
    int minTillNow;
    Node* next;
    Node* prev;
        Node(int val,int minTillNow,Node*next,Node*prev){
            this->minTillNow = minTillNow;
            this->val = val;
            this->next = next;
            this->prev = prev;

        }

        
};
class MinStack {
    Node* topNode;
    int size;
    public:
        MinStack() {
            topNode = new Node(INT_MAX,INT_MAX,nullptr,nullptr);
            size = 0;
        }
        void push (int val){ 
            int minTillNow = std::min(topNode->minTillNow,val);
            Node* newnode = new Node(val,minTillNow,nullptr,topNode);
            topNode->next = newnode;
            topNode=topNode->next;
            size++;
            
        }  
        void pop() { 
            if(size == 0) return;
            Node* prevNode = topNode->prev;
            prevNode->next = nullptr;
            topNode = prevNode;
            size--;
            
        }  
        int top() { 
            if(size == 0) return -1;
            return topNode->val;
        } 
        int getMin() {
            if(size == 0) return -1;
            return topNode->minTillNow;
        }

    };

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl; // return -3 
    minStack.pop();
    std::cout  << minStack.top() << std::endl;// return Ø
    std::cout << minStack.getMin()<< std::endl; // return -2
}