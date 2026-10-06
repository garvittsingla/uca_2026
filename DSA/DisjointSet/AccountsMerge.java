package DisjointSet;


import java.util.*;

public class AccountsMerge {
    class Solution {
        public List<List<String>> accountsMerge(List<List<String>> accounts) {
            int n = accounts.size();
            DSU ds = new DSU(n);
            Map<String, Integer> map = new HashMap<>();

            for(int i = 0 ; i < n ; i++){
                for(int j = 1 ; j < accounts.get(i).size() ; j++){
                    String mail  = accounts.get(i).get(j);
                    if(!map.containsKey(mail)){
                        map.put(mail, i);
                    }else{
                        ds.union(i, map.get(mail));
                    }
                }
            }

            

            HashMap<Integer, List<String>> mpp = new HashMap<>();
            for(Map.Entry<String, Integer> entry : map.entrySet()){
                String mail = entry.getKey();
                int i = entry.getValue();
                int root = ds.findParent(i);
                if(!mpp.containsKey(root)){
                    mpp.put(root, new ArrayList<>());
                }
                mpp.get(root).add(mail);
            }

            List<List<String>> result = new ArrayList<>();
            for(Map.Entry<Integer, List<String>> entry : mpp.entrySet()){
               int root = entry.getKey();
               List<String> list = entry.getValue();
               Collections.sort(list);
               List<String> account = new ArrayList<>();
               account.add(accounts.get(root).get(0)); 
               account.addAll(list);                    
               result.add(account);
            }
            return result;
        }
    }

    public static void main(String[] args) {
        Solution solution = new AccountsMerge().new Solution();
        
            List<List<String>> accounts = Arrays.asList(
                Arrays.asList("John", "johnsmith@mail.com", "john_newyork@mail.com"),
                Arrays.asList("John", "johnsmith@mail.com", "john00@mail.com"),
                Arrays.asList("Mary", "mary@mail.com"),
                Arrays.asList("John", "johnnybravo@mail.com")
            );
        
            List<List<String>> expected = Arrays.asList(
                Arrays.asList("John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"),
                Arrays.asList("Mary", "mary@mail.com"),
                Arrays.asList("John", "johnnybravo@mail.com")
            );
        
            List<List<String>> result = solution.accountsMerge(accounts);
        
            // Since order doesn't matter
            result.sort(Comparator.comparing(a -> a.get(0)));
            expected.sort(Comparator.comparing(a -> a.get(0)));
        
            System.out.println(result.equals(expected) ? "PASS" : "FAIL");
    }
}