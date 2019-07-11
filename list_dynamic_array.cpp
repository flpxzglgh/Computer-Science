#include<iostream>
#include <new>
using namespace std;
class list{
private:
	int mysize;
	int mycapacity;
	int *myarray;
public:
	list(int maxsize=100);
	~list();
	list(const list&ori);
	list &operator=(const list&ori);
	void insert(int value,int pos);
	void del(int pos);
	void display();
	bool empty() const;

};
list&list::operator=(const list & ori)
{

	if(this != &ori){
		mysize=ori.mysize;
		mycapacity=ori.mycapacity;
		if (mycapacity!=ori.mycapacity){
			delete [ ] myarray;
			myarray=new int[mycapacity];
		}

		for(int i=0;i<mycapacity;i++){
			myarray[i]=ori.myarray[i];

		}
	}




return *this;
}

list::list(const list&ori):mysize(ori.mysize),mycapacity(ori.mycapacity){

	myarray=new(nothrow) int[mycapacity];
	if(myarray!=0){
		for(int i=0;i<mycapacity;i++){
			myarray[i]=ori.myarray[i];
		}
	}	
	else{
		cerr<<"this space is not enough"<<endl;
	}

}
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
	delete [] myarray;
	cout<<"this list is already been deleted~";
}

list::list(int maxsize):mysize(0),mycapacity(maxsize){
	myarray=new int[mycapacity];
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


list p=l;
cout<<endl;
p.display();

list o;
o=p;
cout<<endl;
o.display();
o.del(3);
cout<<endl;
o.display();
	return 0;
}