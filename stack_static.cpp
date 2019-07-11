#include <iostream>
using namespace std;


const int mycapacity=128;
typedef int Element;

class stack{
private:
	int mytop;
	int  myarray[mycapacity];
public:
	stack();
	~stack();
	bool empty() const;
	void push(const int &value);
	void display();
	int top() const;
	void pop();
};

stack::stack():mytop(-1){
}
stack::~stack(){
	cout<<"this stack is already been destoried!";
}
bool stack::empty() const{
	return (mytop==-1);

}
void stack::push(const int &value){
	if(mytop<mycapacity-1){
		mytop++;
		myarray[mytop]=value;
	}
	else{
		cerr<<"this stack is full!!"<<endl;
	}

}

int stack::top() const{
		//cerr<<"it is not";
	  return myarray[mytop];
}

void stack::display(){
	for(int i=mytop;i>=0;i--){
		cout<<myarray[i]<<endl;
	}
}

void stack::pop(){

	if(!empty()){
		mytop--;
	}
	else{
		cerr<<"this stac is already empty!";
	}

}

int main(int argc, char const *argv[])
{
	stack s;
	for(int i=0;i<10;i++){
		s.push(i);
	}

	s.display();

	cout<<endl;
	

	cout<<s.top()<<endl;

		for(int i=0;i<5;i++){
		s.pop();
	}
	cout<<endl;
	s.display();


	return 0;
}