public class DesignHashMap{

    class Node<k,v>{
        public k key;
        public v value;
        Node next;
        Node prev;
        Node(k key,v value){
            this.key = key;
            this.value = value;
        }
    }
    class HashMap<k,v>{
        private final int INITIAL_CAPACITY = 4;
        private final int MAX_CAPACITY = 1 << 30;
        private final float LOAD_FACTOR = 0.75f;
        private int countOfNodes = 0;

        private Node[] map;

        HashMap(){
            map = new Node[INITIAL_CAPACITY];
            for(int i = 0 ; i < INITIAL_CAPACITY ; i++){
                map[i] = new Node<>(null,null);
                map[i].next=  new Node<>(null,null);
                map[i].next.prev = map[i];
            }
        }
        public void put(k key, v value){
            Node node = findNode(key);
            if(node!=null){
                node.value = value;
                return;
            }

            int bucket = 
        }
        public Node findNode(k key){
            int bucket = key.hashCode() % map.length;
            Node head = map[bucket];
            while(head!=null){
                if(head.key != null && head.key.equals(key)){
                    return head;
                }
                head = head.next;
            }
            return null;
        }
    }
    public static void main(String[] args) {
	
    }
}