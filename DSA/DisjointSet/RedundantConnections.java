package DisjointSet;

public class RedundantConnections{
    class Solution {
        public int findParent(int child,int[] parent){
            if(parent[child] == child) return child;
    
            parent[child] = findParent(parent[child],parent);
            return parent[child];
        }
        public boolean union(int childA,int childB,int[] parent,int[] size){
            int parentA = findParent(childA,parent);
            int parentB = findParent(childB,parent);
            if(parentA == parentB) return true;
    
            if(parent[parentA] >= parent[parentB]){
                size[parentA] += size[parentB];
                parent[parentB] = parentA;
            }else{
                size[parentB] += size[parentA];
                parent[parentA] = parentB;
            }
    
            return false;
        }
        public int[] findRedundantConnection(int[][] edges) {
            int nodes = edges.length;
    
            int parent[] = new int[nodes+1];
            int size[] = new int[nodes+1];
    
            for(int i = 1 ; i < parent.length ; i++){
                parent[i] = i;
                size[i] = 1;
            }   
    
            int[] ans = new int[2];
    
            for(int i = 0 ; i < edges.length ; i++){
                int childA = edges[i][0];
                int childB = edges[i][1];
    
                if(union(childA,childB,parent,size)){
                    ans[0] = childA;
                    ans[1] = childB;
                }
            }
    
    
         return ans;
    
        }
    }
       
}