
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

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ->";
        head=head->next;
    }
}

int main() {
	// your code goes here
    Node*head=NULL;
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    print(head);
    //print(head);
	return 0;
}

// linkedlist implementation understood and observed very important thing related to pointing n referencing...
