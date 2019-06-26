#include <iostream>
using namespace std;

class circle{
private:
	int r;
	static int count;
public:
	circle(){
		count++;
	}

	int getr() const{
		return r;
	}
	void setr(){
		r=100;
	}
 static int getc(){
		return count;
	}

};

int circle::count=0;
int main(int argc, char const *argv[])
{
	circle c;
	c.setr();
	cout<<c.getr()<<endl;
	cout<<c.getc()<<endl;
	cout<<circle::getc();
	return 0;
}