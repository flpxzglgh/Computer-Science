#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Stack {
private:
  int mycapacity;
  vector<T> v;
  int mytop;

public:
  Stack(int maxsize);
  void push(int value);
  void pop();
  int retrieve_top();
  bool isEmpty();
  void display() const;
  int getthesize() const;
};
template <typename T> int Stack<T>::getthesize() const { return mytop + 1; }

template <typename T> void Stack<T>::display() const {
  for (int i = mytop; i >= 0; i--) {
    cout << v[i] << endl;
  }
}

template <typename T> int Stack<T>::retrieve_top() {
  if (isEmpty()) {
    cerr << "this stack is empty!";
    exit(0);
  } else {
    return v[mytop];
  }
}

template <typename T> bool Stack<T>::isEmpty() { return mytop == -1; }

template <typename T>
Stack<T>::Stack(int maxsize) : mytop(-1), mycapacity(maxsize) {
  v.reserve(mycapacity);
}
template <typename T> void Stack<T>::push(int value) {
  if (mytop == mycapacity) {
    cerr << "this stack is full!" << endl;
  } else {
    v[++mytop] = value;
  }
}
template <typename T> void Stack<T>::pop() {
  if (isEmpty()) {
    cerr << "this stack is empty!";
  } else {
    mytop--;
  }
}

int main() {

  Stack<int> s(10);
  while (1) {
    cout << "what is the fuction?" << endl;
    cout << "1: push\n"
         << "2: pop\n"
         << "3: retrieve top of the stack\n"
         << "4: display the stack\n"
         << "5: get the size of the stack\n"
         << "6: exit\n";
    int choice = 0;
    int value = 0;
    cin >> choice;
    if (choice == 1) {
      cout << "input the value!";
      cin >> value;
      s.push(value);
      s.display();
      continue;

    } else if (choice == 2) {
      s.pop();
      s.display();
      continue;
    }

    else if (choice == 3) {
      cout << s.retrieve_top() << endl;
      continue;
    }

    else if (choice == 4) {
      s.display();
      continue;
    }

    else if (choice == 5) {
      cout << s.getthesize() << endl;
      continue;
    }

    else if (choice == 6) {
      exit(1);
    }

    else {
      cout << "please input correct choice";
      continue;
    }
  }

  return 0;
}