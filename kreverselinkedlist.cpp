#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node( int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value  = this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory Free : "<<value<<endl;
    }
};

void insertAtHead(Node* &head , int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail , int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPos(Node* &head , Node* &tail , int pos ,int d)
{
    //Node* temp = new Node(d);
    if(pos==1)
    {
        insertAtHead(head , d);
        return;
    }
    Node* curr = head;
    int cnt = 1;
    while(cnt<pos-1)
    {
        curr = curr->next;
        cnt++;
    }
    if(curr->next == NULL)
    {
        insertAtTail(tail , d);
        return;
    }

    Node* temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
}

void print(Node* head )
{
    if(head==NULL)
    {
        cout<<"The lsit is empty \n";
        return;
    }

    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reverse(Node* &head , Node* &tail)
{ 

    if(head == NULL)
    {
        cout<<"The list is empty \n";
        return;
    }
    if(head->next == NULL)
    {
        print(head);
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = NULL;
    while(curr!=NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;

    }
    tail = head;
    head = prev;
    print(prev); //prev act as new head of the reversed linked list
    

}
/*void middleofList(Node* &head){
    
}*/

/*void Delete(Node* &head , int pos)
{
    
}*/
Node* kreversed(Node* head , int k)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = NULL;
    int cnt = 0;
    while(curr!=NULL&&cnt<k)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        cnt++;
    }
    if(fwd!=NULL)
    {
        head->next = kreversed(fwd , k);
    }
    return prev;
}
int main()
{
    //int d;
    //cout<<"Enter the value of 1st Node : - ";
    //cin>>d;
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtPos(head , tail , 1 , 6);
    print(head);
    cout<<"head : "<<head->data<<" Tail : "<<tail->data<<endl;
    insertAtPos(head , tail , 3 , 2);
    print(head);
    cout<<"head : "<<head->data<<" Tail : "<<tail->data<<endl;
    insertAtPos(head , tail , 1 , 4);
    print(head);
    cout<<"head : "<<head->data<<" Tail : "<<tail->data<<endl;
    insertAtPos(head , tail , 2 , 5);
    print(head);
    cout<<"head : "<<head->data<<" Tail : "<<tail->data<<endl;
    reverse(head ,tail);
    cout<<"head : "<<head->data<<" Tail : "<<tail->data<<endl;
    //print(head);
    reverse(head,tail);
    print(kreversed(head , 2));
return 0;
}