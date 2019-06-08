#include <iostream>
using namespace std;

void changenumber1(int *,int *);
void changenumber2(int &,int &);
int main(){

	int i=100;
	int y=11;
	//changenumber1(&i,&y);
	changenumber2(i,y);
	cout<<i<<y;
	return 0;
}

void changenumber1(int *u,int *p){

	swap(*u,*p);
}

void changenumber2(int &u,int &p){
	swap(u,p);
}