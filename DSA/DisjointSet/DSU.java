package DisjointSet;

public class DSU{
    private int n;
    private int[] parent;
    private int[] size;

    DSU(int n){
        this.n = n;
        this.parent = new int[n];
        this.size = new int[n];

        for(int i = 0;i < n ;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int findParent(int child){
        if(child == parent[child]) return child;

        int ultimateParent = findParent(parent[child]);
        return ultimateParent;
    }

    public void union(int childA,int childB){
        int parentA = findParent(childA);
        int parentB = findParent(childB);

        if(parentA == parentB) return;

        if(size[parentA] < size[parentB]){
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }else{
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        }
    }
}