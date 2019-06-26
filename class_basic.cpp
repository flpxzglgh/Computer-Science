#include <iostream>
using namespace std;

class circle{
private:
	int r;
	int count;
public:
	circle(){
		//r=100;
		//count++;
	}

	int getr() const{
		return r;
	}
	void setr(){
		r=100;
	}

};


int main(int argc, char const *argv[])
{
	circle c;
	c.setr();
	cout<<c.getr()<<endl;
	return 0;
}