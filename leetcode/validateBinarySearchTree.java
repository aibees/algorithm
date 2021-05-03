//import java.util.*;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    HashMap<Integer, Boolean> hm = new HashMap<Integer, Boolean>();
    
    boolean ret = true;
    int iniMin = -2147483648;
    int iniMax = 2147483647;
    
    public boolean isValidBST(TreeNode root) {
        
        hm.put(root.val, true);
        
        if(root.left != null) {
            check(root.left , iniMin, root.val);
        }
        if(root.right != null) {
            check(root.right, root.val, iniMax);
        }
        
        boolean answer = ret;
        return answer;
    }

                               
    private void check(TreeNode t, int less, int more) {
        if(!ret) {
            return;
        }
        
        if(hm.containsKey(t.val)) {
            ret = false;
            return;
        }
        else {
            hm.put(t.val, true);
        }
        
        if(t.val >= less && t.val <= more) {
            
            if(t.left != null) {
                check(t.left , less, t.val);
            }
            if(t.right != null) {
                check(t.right, t.val, more);
            }
        }
        else {
            ret = false;
            return;
        }
    }
}