#include <iostream>
using namespace std;

class node{
        public:
        int data;
        node* prev;
        node* next;

        node() {
                this->data = 0;
                this->prev= NULL;
                this->next = NULL;
        }
        node(int data) {
                this->data = data;
                this->prev = NULL;
                this->next = NULL;
        }

        ~node() {
                cout << "node with value: " << this->data << " deleted" << endl;
        }
};
//PRINTING DOUBLY LINKED LIST
void print(node* &head) {
        node* temp = head;

        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp->next;
        }
}


int getLength(node* head) {
        int len = 0;
        node* temp = head;

        while(temp != NULL) {
                temp = temp -> next;
                len++;
        }
        return len;
}
//INSERT AT HEAD
void insertAtHead(node* &head, node* &tail, int data) {
        if(head == NULL) {
                //LL is empty
                node* newnode = new node(data);
                head = newnode;
                tail = newnode;
        }
        else {
                //LL is non-empty
                //step1: create a node
                node* newnode = new node(data);
                //step2:
                newnode ->next = head;
                //step3:
                head ->prev = newnode;
                //step4;
                head = newnode;
        }

}
//INSERT AT TAIL
void insertAtTail(node* &head, node* &tail, int data) {

        if(head == NULL) {
                //LL is empty
                node* newnode = new node(data);
                head = newnode;
                tail = newnode;
        }
        else {
                //LL is not empty
                node* newnode = new node(data);
                tail ->next = newnode;
                newnode ->prev = tail;
                tail = newnode;
        }

}
 
 //INSERT WITH TWO VARIANBLE

void insertAtPosition(node* &head, node* &tail, int data, int position) {
        if(head == NULL) {
                node* newnode = new node(data);
                head = newnode;
                tail = newnode;
        }
        else {
                //LL is not empty
                if(position <= 1) {
                        insertAtHead(head,tail, data);
                        return;
                }
                int len = getLength(head);
                if(position > len) {
                        insertAtTail(head, tail, data);
                        return;
                }
                // insertion in middle
                //step1: find prev && curr
                int i = 1;
                node* prevnode = head;
                while( i < position - 1) {
                        prevnode = prevnode ->next;
                        i++;
                }
                node* curr = prevnode -> next;

                //step2: create a node
                node* newnode  = new node(data);

                //step3:
                 newnode -> prev = prevnode;
                prevnode -> next = newnode;
                newnode ->next = curr;
                curr -> prev = newnode;
                
        }
}
/////insesrt without curr 
void insesrtwithoutcurr(node* &head,node* &tail,int data,int position)
{
    if(head == NULL) {
                node* newnode = new node(data);
                head = newnode;
                tail = newnode;
        }
        else {
                //LL is not empty
                if(position <= 1) {
                        insertAtHead(head,tail, data);
                        return;
                }
                int len = getLength(head);
                if(position > len) {
                        insertAtTail(head, tail, data);
                        return;
                }
                // insertion in middle
                //step1: find prev && curr
                int i = 1;
                node* prevnode = head;
                while( i < position - 1) {
                        prevnode = prevnode ->next;
                        i++;
                }

                //step2: create a node
                node* newnode  = new node(data);

                //step3:
                prevnode->next->prev=newnode;
                newnode->prev=prevnode;
                 newnode->next=prevnode->next;
                prevnode->next=newnode;
                
        }
}
void deleteatpositon(node* &head,node* &tail,int position)
{
    if(head==NULL)
    {
        cout<<"can,t delete linked list is empty"<<endl;
        return;
    }
    if(head->next==NULL)
    {
        node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
     // deleting at head
    if(position==1)
    {
        node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    // deleting at tail
    int len=getLength(head);
    if(position==len)
    {
        node* temp=tail;
        tail=tail->prev;
        temp->prev=NULL;
        tail->next=NULL;
        delete temp;
        return;
    }
    // deleting at any position
    //step1
    int i=1;
    node* left=head;
    while(i<position-1)
    {
        left=left->next;
        i++;
    }
    node  *curr=left->next;
    node *right=curr->next;
    //step 2
    left->next=right;
    //step3
    right->prev=left;
    //step4
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;
    
}


int main()
{
    node* first=new node(10);
    node* second=new node(30);
    node* third=new node(40);
    node* fourth=new node(50);
    
    node* head=first;
    node* tail=fourth;
    
     first->next=second;
     second->prev=first;
     second->next=third;
     third->prev=second;
     third->next=fourth;
     
    cout<<"------printing the linked list----"<<endl;
    print(head);
    cout<<endl<<"----inserting at head------"<<endl;
    insertAtHead(head,tail,80);
    print(head);
    cout<<endl<<"----inserting at tail------"<<endl;
    insertAtTail(head,tail,1020);
    print(head);
    cout<<endl<<"----inserting at middle position------"<<endl;
    insertAtPosition(head,tail,21,1);
    print(head);
    cout<<endl<<"---inserting without using curr variable at middle position------"<<endl;
    insesrtwithoutcurr(head,tail,30,48);
    print(head);
    cout<<endl<<"----delete a node with starting position----"<<endl;
    deleteatpositon(head,tail,1);
    print(head);
    cout<<endl<<"----delete a node at last position----"<<endl;
    deleteatpositon(head,tail,7);
    print(head);
    cout<<endl<<"----delete a node at last position----"<<endl;
    deleteatpositon(head,tail,7);
    print(head);
    cout<<endl<<"----delete a node at any position----"<<endl;
    deleteatpositon(head,tail,2);
    print(head);
     return 0;
}