#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t=10;
	int *u=nullptr;
	u=&t;
	int **p=&u;
	cout<<&t<<" "<<u<<" "<<&u<<endl;
	cout<<p<<" "<<*p<<" "<<**p;
	

	int const *r=&t; //*r cannot change
	const int  *ll=&t; //*ll cannot change
	
	int  * const h=&t; //  h cannot change
	*h=11111;

	int *ia;
	ia=new int[10];
	ia[1]=99;
	cout<<ia[1];
	delete ia;
	return (0);
}