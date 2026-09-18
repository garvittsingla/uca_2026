import java.util.*;

public class searchLinkedList {
    static class Node{
        public int val;
        public Node nextNode;
        Node(int val,Node nextNode){
            this.val = val;
            this.nextNode = nextNode;
        }
        
    }

    private static Node populateList(ArrayList<Integer> arr){
        Node dummy = new Node(-1,null);
        Node temp = dummy;
        for(Integer it:arr){
            Node newNode = new Node(it,null);
            temp.nextNode = newNode;
            temp = temp.nextNode;
            
        }
        return dummy.nextNode;
        
    }

    private static void printList(Node head){
        Node current = head;
        while(current != null){
            System.out.print(current.val + "->");
            current = current.nextNode;
        }
        System.out.println();
    }

    private static boolean search(Node head, Node target) {
       Node p1 = head;
       Node p2 = target;

       while(p1 != null){
           if(p1.val == p2.val){
               Node temp = p1;
               while(p1 != null && p2 != null){
                   if(p1.val != p2.val){
                       break;
                   }
                   p1 = p1.nextNode;
                   p2 = p2.nextNode;
               }
               if(p2 == null){
                   return true;
               }
               p1 = temp;
               p2 = target;
           }
           p1 = p1.nextNode;
       }
       return false;
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr1 = new ArrayList<>(Arrays.asList(1,10,20));
        ArrayList<Integer> arr2 = new ArrayList<>(Arrays.asList(10,20));

        Node head1 = populateList(arr1);
        Node head2 = populateList(arr2);
           
        printList(head1);
        printList(head2);

        System.out.println("the anwer for this query is " + search(head1, head2));

        ArrayList<Integer> arr3 = new ArrayList<>(Arrays.asList(1,2,1,2,3,4));
        ArrayList<Integer> arr4 = new ArrayList<>(Arrays.asList(1,2));

        
        Node head3 = populateList(arr3);
        Node head4 = populateList(arr4);
        printList(head3);
        printList(head4);
        System.out.println("the anwer for this query is " + search(head3, head4));


        ArrayList<Integer> arr5 = new ArrayList<>(Arrays.asList(1,2,3,4));
        ArrayList<Integer> arr6 = new ArrayList<>(Arrays.asList(1,2,2,1,2,3));

        Node head5 = populateList(arr5);
        Node head6 = populateList(arr6);
        printList(head5);
        printList(head6);
        System.out.println("the anwer for this query is " + search(head5, head6));
        
    }
}