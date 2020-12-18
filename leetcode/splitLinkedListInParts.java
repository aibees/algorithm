/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] answer = new ListNode[k]; 
        
        Stack<ListNode> nodes = new Stack<ListNode>();
        Stack<ListNode> listStack = new Stack<ListNode>();
        
        if(root == null) {
            return answer;
        }
        if(root.next == null) {
            answer[0] = root;
            return answer;
        }
        
        // input
        while(root.next != null) {
            nodes.push(root);
            root = root.next;
        }
        nodes.push(root);
        int cnt = nodes.size();
        
        // cut
        int splitCnt = cnt / k;
        int more = cnt % k;
        
        for(int i = 0; i < k-more; i++) {
            ListNode sub = null;
            for(int j = 0; j < splitCnt; j++) {
                ListNode tmp = nodes.peek();
                nodes.pop();
                tmp.next = sub;
                sub = tmp;
            }
            listStack.push(sub);
        }
        
        for(int i = 0; i < more; i++) {
            ListNode sub = null;
            for(int j = 0; j < splitCnt+1; j++) {
                ListNode tmp = nodes.peek();
                nodes.pop();
                tmp.next = sub;
                sub = tmp;
            }
            listStack.push(sub);
        }
        int idx = 0;
        while(!listStack.empty()) {
            answer[idx] = listStack.peek();
            listStack.pop();
            idx++;
        }
        
        return answer;
    }
}