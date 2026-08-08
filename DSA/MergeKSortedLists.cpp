#include<iostream>
#include <vector>

class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(){};
        ListNode(int val){this->val = val;}
        ListNode(int val,ListNode *next){
            this->val = val;
            this->next = next;
        }

};

ListNode* mergeTwoLists(ListNode* headA,ListNode* headB){
    ListNode* dummy = new ListNode(-1);
    ListNode* ans = dummy;
    ListNode* l1 = headA;
    ListNode* l2 = headB;
    while(l1  && l2){
        if(l1->val <= l2->val){
            ListNode* newnode = new ListNode(l1->val);
            l1 = l1->next;
            ans->next = newnode;
            ans = newnode;
        }else{
            ListNode* newnode = new ListNode(l2->val);
            l2 = l2->next;
            ans->next = newnode;
            ans = newnode;
        }
    }


    while(l1){
         ListNode* newnode = new ListNode(l1->val);
            l1 = l1->next;
            ans->next = newnode;
            ans = newnode;
    }
    while(l2){
         ListNode* newnode = new ListNode(l2->val);
            l2 = l2->next;
            ans->next = newnode;
            ans = newnode;
    }
    return dummy->next;
}
ListNode* mergekLists(std::vector<ListNode*> lists){
    ListNode* prevHead = lists[0];
    for(int i = 1; i  < lists.size() ; i++){
        prevHead = mergeTwoLists(prevHead,lists[i]);
    }

    return prevHead;
}

void printList(ListNode* head){
    while(head){
        std::cout << head -> val << std::endl;
        head=head->next;

    }
}
int main(){
    ListNode* firstList = new ListNode(1);
    firstList->next = new ListNode(4);
    firstList->next->next =  new ListNode(5);


    ListNode* secondList = new ListNode(1);
    secondList->next = new ListNode(3);
    secondList->next->next =  new ListNode(4);

    ListNode* thirdList = new ListNode(2);
    thirdList->next = new ListNode(6);
   
    std::vector<ListNode*> testCase1 = {firstList,secondList,thirdList};
    ListNode* ans = mergekLists(testCase1);

    printList(ans);
    

}