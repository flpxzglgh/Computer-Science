
//static_stack
#include <iostream>
using namespace std;
const int mycapacity=100;
class stack{
private:
	int mytop;
	int array[mycapacity];
public:
	stack();
	bool empty() const;
	void push(int value);
	void pop();
	int top() const;//retrive the top
	void display();
};

void stack::display(){
	
	for(int i=mytop;i>-1;i--){
		cout<<array[i]<<endl;
	}


}

void stack::pop(){
	if(mytop!=-1){
		mytop--;
	}
	else{
		cerr<<"this stack is empty!"<<endl;
	}
}

void stack::push(int value){
	if(mytop!=mycapacity){
		mytop++;
		array[mytop]=value;
		
	}
	else{
		cerr<<"this stack is already full!";
	}
}




bool stack::empty()const{
	return mytop==-1;
}

stack::stack():mytop(-1){

}



int main(int argc, char const *argv[])
{
	stack s;
	s.push(1);
	s.display();
	s.push(3);
	s.pop();
	s.display();

	
	return 0;
}
