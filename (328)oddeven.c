//328.ODD EVEN LIST
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL|| head->next==NULL){
    return head;
    }
    struct ListNode* temp=head->next;
    struct ListNode* cur=head;
    struct ListNode* new=temp;
    while(temp!=NULL && temp->next!=NULL){
      cur->next=cur->next->next;
      cur=cur->next;
      temp->next=temp->next->next;
      temp=temp->next;
    }
    cur->next=new;
    return head;
}
