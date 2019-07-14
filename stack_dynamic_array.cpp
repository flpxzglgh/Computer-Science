// stack_dynamic_array

#include <iostream>
using namespace std;

class stack{
private:
	int mytop;
	int mycapacity;
	int *myarray;
public:
	stack(int maxsize);
	~stack();
	bool empty() const;
	stack(const stack& ori);
	stack &operator=(const stack & ori);
	void push(int value);
	void pop();
	void display();
	void gettop();
	
};

void stack::gettop(){
	if(!empty()){
		cout<<myarray[mytop]<<endl;
	}
	else{
		cerr<<"this list is empty!"<<endl;
	}
}

void stack::display(){
	if(!empty()){
		for(int i=mytop;i>-1;i--){
			cout<<myarray[i]<<endl;
		}
	}
}

void stack::pop(){
	if(!empty()){
		mytop--;
	}
	else{
		cerr<<"this list is empty!"<<endl;
	}

}
void stack::push(int value){
	if(mytop!=mycapacity){
		mytop++;
		myarray[mytop]=value;
	}
	else{
		cerr<<"this stack is already full!"<<endl;
	}
}
stack & stack::operator=(const stack& ori){
	mytop=ori.mytop;
	mycapacity=ori.mycapacity;
	delete [] myarray;
	myarray=new int[mycapacity];
		if (myarray!=0){
		for(int i=0;i<mycapacity;i++){
			myarray[i]=ori.myarray[i];
		}
	}

return *this;
}
stack::stack(const stack&ori):mytop(ori.mytop),
mycapacity(ori.mycapacity){
	myarray=new int[mycapacity];
	if (myarray!=0){
		for(int i=0;i<mycapacity;i++){
			myarray[i]=ori.myarray[i];
		}
	}
	else{
		cerr<<"this memory is not enough!";
	}
}
bool stack::empty() const{
	return mytop==-1;
}
stack::stack(int maxsize):mytop(-1),mycapacity(maxsize){
	myarray=new int[mycapacity];
	}


stack::~stack(){
	delete [] myarray;
	}
int main()
{
	stack s(100);
	for(int i=0;i<10;i++)
		s.push(i);
	s.display();
	cout<<endl;
	s.pop();
		s.display();
			cout<<endl;
	s.gettop();
		

	return 0;
}
