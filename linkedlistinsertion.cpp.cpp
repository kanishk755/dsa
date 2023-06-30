#include<bits/stdc++.h>
using namespace std;
class node {
	public:
		int data;
		node* next;
		node() {
			this->data=0;
			this->next=NULL;
		}
		node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
		
};
//PRINTING
void print(node* &head)
{
    node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
//INSERT AT HEAD
void insertathead(node* &head,int data)
{  
    //step 1-
    node* newnode=new node(data);
      //step 2-
      newnode->next=head;
      //step-3
      head=newnode;
    
}
//tail isliye pass kiya because newnode agr phli node ho to usko head and tail dono se initialise krna pdega
void insertathead(node* &head,node* &tail,int data)
{  
    if(head==NULL)
      {
          node* newnode=new node(data);
          head=newnode;
          tail=newnode;
          return ;
      }
    //step 1-
    node* newnode=new node(data);
      //step 2-
      newnode->next=head;
      
      //step-3
      head=newnode;
    
}
void insertattail(node *&head,node *tail,int data)
{
    if(head==NULL)
      {
          node* newnode=new node(data);
          head=newnode;
          tail=newnode;
          return ;
      }
        node *newnode=new node(data);
        tail->next=newnode;
        tail=newnode;
    
}

int main() {
    /* --------PRINTING BY CREATING NODE----
    node* first=new node(10);
     node* second=new node(20);
    node* third=new node(30);
     node* fourth=new node(40);
     first->next=second;
     second->next=third;
     third->next=fourth;
     cout<<"printing the LL"<<endl;
     print(first);
     */ 
     
     
      //inserting without null------
    //  node *head=new node(20);
    //  insertathead(head,30);
    //   insertathead(head,50);
    //      insertathead(head,600);
    //       insertathead(head,40);
    //       cout<<"printing by inserting at head without null"<<endl;
    //       print(head);
    //       cout<<endl;
    
    
    //inserting if head and tail are null
    node* head= NULL;
    node* tail=NULL;
     insertathead(head,tail,10);
       insertathead(head,tail,20);
         insertathead(head,tail,30);
           insertathead(head,tail,40);
             insertattail(head,tail,100);
             print(head);
           
	return 0;
	
}