#include <iostream>
using namespace std;

class Node{
public:
	Node* next;
	int data;
};

class Linkedlist{
public:
	int size;//the list size;
	Node* head;
	Linkedlist();
	~Linkedlist();
	void insert_at_begining(int data);
	void insert_at_end(int data);
	void insert_at_position(int,int);
	void delete_at_position(int);
	void delete_at_begining();
    void delete_at_end();

	void display();
};
 
Linkedlist::Linkedlist(){
	this->size=0;
	this->head=NULL;
}

Linkedlist::~Linkedlist(){
	cout<<"LIST DELETED";
}

void Linkedlist::insert_at_begining(int data){
	Node*node=new Node();
	node->data=data;
	node->next=this->head;
	this->head=node;
	this->size++;
}
 void Linkedlist::insert_at_end(int data){
 	Node *p = new Node;
    Node *r = new Node;
    Node *q = new Node;
    r = this->head;
    p->data = data;
    p->next = NULL;
    if(head == NULL){
        head = p;
    }else{
        while(r->next!=NULL){
            r = r->next;
        }
        r->next = p;
    }
 }

void Linkedlist::insert_at_position(int value,int position){
	Node *p = new Node;
    Node *l = new Node;
    Node *r = new Node;
    bool isFound = false;
    p=head;
    int count=0;
    while(p != NULL){
        if(count == position){
            isFound = true;
            break;
        }
        count++;
        l = p;
        p = p->next;

    }
    r->data=value;
    l->next = r;
    r->next = p;
    if(isFound==false){
    	cout<<"Bad position! Enter the data again!"<<endl;
    	int v,p;
    	cin>>v>>p;
    	insert_at_position(v,p);
    }
}

void Linkedlist::display(){
	Node* h = this->head;
	int i=1;
	while(h){
		cout<<i-1<<":"<<h->data<<endl;
		h=h->next;
		i++;
	}
}

void Linkedlist::delete_at_position(int position){
	Node *p = new Node;
    Node *r = new Node;
    bool isFound = false;
    p = head;
    int count=0;
    while(p!=NULL){
        if(count == position-1){
            isFound = true;
            break;
        }
        p = p->next;
        r=p->next;
        count++;
       
    }
   		p->next=r->next;
   		delete r;


}

void Linkedlist::delete_at_begining(){
   Node *p = new Node;
    if(head == NULL){
        cout<<"\nList is Empty\n";
    }else{
        p = head;
        head = head->next;
        delete p;
    }

}

void Linkedlist::delete_at_end(){

	Node *p = new Node;
  	Node *l = new Node;
  if(head == NULL){
    cout<<"\nList is Empty\n";
  }else{
    p = head;
    if(p->next == NULL){
        head = NULL;
        delete p;
    }else{
        while(p->next!= NULL){
            l = p;
            p = p->next;
        }
        l->next = NULL;
        delete p;
    }
  }
}

int main()
{
	
	Linkedlist* list = new Linkedlist();

/*
	for (int i = 0; i < 11; ++i)
   {
       list->insert_at_begining(i);
   }
   list->display();
   cout<<endl;
   list->insert_at_position(333,1);
   list->display();

 cout<<endl;
 list->delete_at_position(3);
    list->display();

cout<<endl;
   list->insert_at_position(999,3);
   list->display();*/

   for (int i = 0; i < 11; ++i)
   {
       list->insert_at_end(i);
   }
   list->display();

 cout<<endl;
 for (int i = 0; i < 3; ++i)
   {
       list->delete_at_begining();
   }
   list->display();
 cout<<endl;
for (int i = 0; i < 3; ++i)
   {
       list->delete_at_end();
   }
   list->display();

   //std::cout << "List Length: " << list->length << std::endl;
   delete list;
	return 0;
}
