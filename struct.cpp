#include <iostream>
using namespace std;

struct apple {
  int t;

public:
  void sett();
};

void apple::sett() { t = 111; }

int main(int argc, char const *argv[]) {

  apple p;
  p.sett();
  cout << p.t;

  return 0;
}