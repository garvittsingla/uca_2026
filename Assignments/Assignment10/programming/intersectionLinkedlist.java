import java.util.*;

public class intersectionLinkedlist{
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

    private static Node getIntersection(Node head1,Node head2){
        Node p1 = head1;
        Node p2 = head2;
        
        Node result = new Node(-1,null);
        Node temp = result;
        
        while(p1 != null && p2!=null){
            if(p1.val == p2.val){
                Node newNode = new Node(p1.val,null);
                temp.nextNode = newNode;
                temp = temp.nextNode;
                p1 = p1.nextNode;
                p2 = p2.nextNode;
            }else{
                if(p1.val < p2.val){
                    p1 = p1.nextNode;
                }else{
                    p2 = p2.nextNode;
                }
            }
        }
        return result.nextNode;
    }

    public static void main(String[] args) {
         ArrayList<Integer> arr1 = new ArrayList<>(Arrays.asList(1,2,3,4,6));
         ArrayList<Integer> arr2 = new ArrayList<>(Arrays.asList(2,4,6,8));

         Node head1 = populateList(arr1);
         Node head2 = populateList(arr2);
            
         printList(head1);
         printList(head2);

         System.out.println("After the function call new linked list is:");

         Node intersection = getIntersection(head1,head2);
         printList(intersection);

            
    }
}