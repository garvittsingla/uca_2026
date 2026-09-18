import java.util.*;

public class reverseLinkedList{
    static class Node{
        public int val;
        public Node nextNode;
        Node(int val,Node nextNode){
            this.val = val;
            this.nextNode = nextNode;
        }
        
    }

    private static void printList(Node head){
        Node current = head;
        while(current != null){
            System.out.print(current.val + "->");
            current = current.nextNode;
        }
        System.out.println();
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

    private static Node reverseList(Node current,Node prev){
        if(current == null) return prev;
        Node nextNode = current.nextNode;
        current.nextNode = prev;
        return reverseList(nextNode,current);
    }

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(1,2,3,4,5,6,7));
        Node head = populateList(arr);

        System.out.println("LinkedList before reverse:");
        printList(head);
        Node reversedHead = reverseList(head,null);
        System.out.println("LinkedList after reverse:");
        printList(reversedHead);
        
    }
}