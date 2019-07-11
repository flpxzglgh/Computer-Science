#include<iostream>
using namespace std;

	const int mycapacity=100;
class list{
private:
	int mysize;
	int myarray[mycapacity];
public:
	list();
	~list();
	void insert(int value,int pos);
	void del(int pos);
	void display();
	bool empty() const;

};
void list::display(){
	if (!empty()){
		for (int i = 0; i < mysize; ++i)
		{
			cout<<myarray[i]<<endl;
		}
	}

	else {cerr<<"this is empty";}
}

bool list::empty()const{
	return mysize==0;
}
void list::del(int pos){
	if(mysize==0){
		cerr<<"this is an empty list";
	}
	if(pos<0||pos>mysize){
		cerr<<"this position is not good";
	}
	else{
		for(int i=pos;i<mysize;i++){
			myarray[i]=myarray[i+1];
		}
		mysize--;
	}

}



void list::insert(int value,int pos){
	if(mysize==mycapacity){
		cerr<<"this list is full!";
	}
	if (pos<0||pos>mysize){
		cerr<<"this is a bad position!";
	}
	else{
		for(int i=mysize;i>pos;i--){
			myarray[i]=myarray[i-1];

		}
		myarray[pos]=value;
		mysize++;
	}
}

list::~list(){
	cout<<"this list is already been deleted~";
}

list::list():mysize(0){
}

int main(int argc, char const *argv[])
{
list l;
for(int i=0;i<10;i++){
	l.insert(i,i);
}

l.display();
cout<<endl;
l.del(1);
l.display();
	return 0;
}