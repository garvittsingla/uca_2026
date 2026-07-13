public class TowerOfHanoi{
    static int towerOfHanoi(int n, char fromRod, char toRod, char auxRod){
        if (n == 0) return 0;
        int a = towerOfHanoi(n - 1, fromRod, auxRod, toRod);
        System.out.println("Disk " + n + " moved from "+ fromRod + " to " + toRod);
        int b = towerOfHanoi(n - 1, auxRod, toRod, fromRod);
        return a+b+1;
    }
    public static void main(String args[]){
        int n = 3;
        
        // A, B and C are names of rods
        int steps = towerOfHanoi(n, 'A', 'C', 'B');
        System.out.println(steps);
    }
}