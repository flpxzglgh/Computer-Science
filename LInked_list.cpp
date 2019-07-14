#include <iostream>
using namespace std;
class Node{
public:
	Node *next;
	int data;
};
class link{
public:
	Node *head;
	link();
	~link();
	void insert_at_begining(int value);
	void insert_at_end(int value);
	void insert_at_position(int,int);
	void delete_at_position(int);
	void delete_at_begining();
    void delete_at_end();
	void display();
};

void link::display(){
	Node *first=new Node;
	first=head;
	while(first){
		cout<<first->data<<endl;
		first=first->next;
	}
}


void link::delete_at_position(int pos){
	if(head==0){
		cout<<"this list is empty"<<endl;
	}
	else {
		Node *p=new Node;
		Node *r=new Node;
		Node *stroe=new Node;
		bool isf(0);
		stroe=head;
		int count=0;
	if(pos==0){
		delete_at_begining();
	}else{
		while(stroe!=0){
			if(count==pos){
				isf=1;
				break;}
			p=stroe;
			count++;
			stroe=stroe->next;
		}
		if(isf){
			if(p->next==0){
				delete_at_end();
			}else{
				p->next=stroe->next;
				delete stroe;
			}
			}


			else {
				cout<<"this is bad";
			}



		}
	}
}

void link::delete_at_end(){
	Node *stroe=new Node;
	Node *l=new Node;
 		stroe=head;
	while(stroe->next!=0){
		l=stroe;
		stroe=stroe->next;
	}
	stroe=0;
	l->next=stroe;

	delete stroe;
}

void link::delete_at_begining(){
	Node*stroe=new Node;
	if(head==0){
		cout<<"this list is empty!";
	}
	else{
		stroe=head;
		head=head->next;
		delete stroe;
	}
}
void link::insert_at_position(int value,int pos){
	Node *nnode=new Node;
	Node *stroe=new Node;
	Node *l=new Node;
	bool isf=0;
	nnode->data=value;
	stroe=head;
	int count=0;
	if(pos==0){
		insert_at_begining(value);
	}else{
		while(stroe!=0){
			if(count==pos){
				isf=1;
				break;}
			l=stroe;
			count++;
			stroe=stroe->next;
			//cout<<count*10<<endl;
		}
		if(isf){
			if(l->next==0){
				insert_at_end(value);
			}else{
				l->next=nnode;
				nnode->next=stroe;}
			}


			else {
				cout<<"this is bad";
			}



		}

}

void link::insert_at_begining(int value){
	Node *nnode=new Node;
	nnode->data=value;
	nnode->next=head;
	head=nnode;
}

void link::insert_at_end(int value){
	Node *nnode=new Node;
	Node *stroe=new Node;
	nnode->data=value;
	nnode->next=0;
	stroe=head;
	if(head==0){
		head=nnode;
	}else{
		while(stroe->next!=0){
			stroe=stroe->next;
		}

	stroe->next=nnode;

	}


}

link::~link(){
	cout<<"this list is gone"<<endl;
}


link::link(){
	head=0;
}



int main(int argc, char const *argv[])
{
	link l;

	for(int i=0;i<10;i++){
		l.insert_at_end(i);
	}


	l.display();
	cout<<endl;
	l.insert_at_position(111,9);
	l.display();
	l.delete_at_begining();
	l.display();
	cout<<endl;
	l.delete_at_end();
	l.display();

cout<<endl;
	l.delete_at_position(3);
	l.display();

		return 0;
}
