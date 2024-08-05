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
    public ListNode removeElements(ListNode head, int val) {
        ListNode temp=head;
        ListNode h=null;
        if(head!=null&&head.val==val)
        {
            h=head;
            while(h!=null)
            {
                if(head.val==val)
                {
                    head=head.next;
                }
                else
                break;
                h=h.next;
            }
        }
        temp=head;
        while(temp!=null)
        {
            if(temp.next==null)
            {
                break;
            }
            else
            {
                if(temp.next.val==val)
                {
                    ListNode y=temp.next;
                        while(y!=null)
                        {
                            if(y.val==val)
                            {
                                temp.next=y.next;
                            }
                            else
                            break;
                            y=y.next;
                        }
                }
            }
            temp=temp.next;
        }

        return head;
    }
}