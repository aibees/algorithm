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

// ================== REAL SOLUTION ====================
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null; // 새로 만들어서 반환할 객체
        ListNode curr = head; // 기존 list에 대한 pointer를 잡는다.
        
        while(curr != null){
            ListNode ahead = curr.next; //pointer next 객체를 잡고
            curr.next = prev ;  // 끄트머리를 현재 pointer next에 넣는다.
            
            prev = curr; // 
            curr = ahead;
        }
            
        return prev;
        
    }
}
// =====================================================


class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode answer = null;
        Stack<ListNode> st = new Stack<ListNode>();
        
        if(head == null || head.next == null) {
            return head;
        }
        
        while(head.next != null) {
            st.push(head);
            head = head.next;
        }
        st.push(head);
        
        answer = st.peek();
        st.pop();
        
        ListNode curr = answer;
        while(!st.empty()) {
            ListNode tmp = st.peek();
            st.pop();
            curr.next = tmp;
            curr = curr.next;
        }
        curr.next = null;
        
        return answer;
    }
}