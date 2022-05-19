
#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    //constructor
    Node(int d){
       data = d;
       next = NULL;
    }
};

void build(){

}
int length(Node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

// here passed a pointer by reference..
void insertAtHead(Node*&head,int d){

    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node* n = new Node(d);
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head,int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = new Node(d);
   
}
void insertInMiddle(Node*&head,int d,int p){
    if(head==NULL || p==0){
        insertAtHead(head,d);
    }
    else if(p>length(head)){
        insertAtTail(head,d);
    }
    else{
        int jump = 1;
        Node* temp = head;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
        }
        Node* n = new Node(d);
        n->next = temp->next;
        temp->next = n;
        

    }
}


void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ->";
        head=head->next;
    }
}

int main() {
	// your code goes here
    Node*head=NULL;
    
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    print(head);
    cout<<endl;
    insertInMiddle(head,4,3);
    insertAtTail(head,7);
    print(head);
    
	return 0;
}

// linkedlist implmentation practice
