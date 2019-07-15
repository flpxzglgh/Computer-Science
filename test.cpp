
//search liner
#include <iostream>
#include <vector>
using namespace std;

template <class t>
class list{
private:
	vector<t> v;
public:
	void insert(int value,int pos);
	void del_at_postion(int pos);
	void display();
	int liner_search(int value) ;
	int binary_search(int value);
	bool empty();
};

template <class t>
void list<t>::insert(int value,int pos){
	v.insert(v.begin()+pos,value);
	
}

template<class t>
void list<t>::del_at_postion(int pos){
	v.erase(v.begin()+(pos-1));
}

template<class t>
void list<t>::display(){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}


template<class t>
int list<t>::binary_search(int value){
int first,mid=0,end;

first=0;//v[0];
end=v.size()-1;
bool isfound=false;
while(isfound||first<=end)
{     mid=(first+end)/2;
	if(v[mid]==value){
		isfound==1;
		cout<<"asdasdasd:  "<<mid<<endl;}
		
	else if(v[mid]<value){
		first=mid+1;
		cout<<"asdasdasd"<<endl;
	}
	else {
		cout<<"asdasdasd"<<endl;
		end=mid-1;
	}

}
return mid;

}



template<class t>
int list<t>::liner_search(int value) {
	bool isfound=false;
	int count=0;

	while(count<=v.size()||isfound){
		if(v[count]==value){
			isfound=true;
			//break;
		}
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	list<int> l;
	for(int i=0;i<10;i++){
		l.insert(i,i);
	}
	l.display();
	cout<<endl;
	l.del_at_postion(1);
	l.display();
	cout<<endl;
	cout<<endl;
	cout<<"this is :  "<<l.liner_search(2);
cout<<endl;
	cout<<endl;
	//cout<<"this is :  "<<l.binary_search(6);





	return 0;

}
