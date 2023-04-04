#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_SIZE 100

class Stack {
  private:
    int t;
    int a[MAX_SIZE];

  public:
    Stack() {
      t = -1;
    }

    bool push(int p) {
      if (t >= (MAX_SIZE - 1)) {
        cout << "Error: stack overflow\n";
        return false;
      } else {
        a[++t] = p;
        cout << p << " push to stack\n";
        return true;
      }
    }

    int pop() {
      if (t < 0) {
        cout << "Error: stack underflow\n";
        return 0;
      } else {
        int p = a[t--];
        return p;
      }
    }

    bool isEmpty() {
      return (t < 0);
    }

    bool isFull() {
      return (t >= (MAX_SIZE - 1));
    }

    int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return a[t];
      }
    }

    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack: ";
        for (int i = t; i >= 0; i--) {
          cout << a[i] << " ";
        }
        cout << endl;
      }
    }
};

int main() {
  auto start_time = high_resolution_clock::now();
  Stack stack;
  stack.push(8);
  stack.push(10);
  stack.push(5);
  stack.push(11);
  stack.push(15);
  stack.push(23);
  stack.push(6);
  stack.push(18);
  stack.push(20);
  stack.push(17);
  stack.Display();
  cout << stack.pop() << " pop from stack\n";
  cout << stack.pop() << " pop from stack\n";
  cout << stack.pop() << " pop from stack\n";
  cout << stack.pop() << " pop from stack\n";
  cout << stack.pop() << " pop from stack\n";
  stack.Display();
  stack.push(4);
  stack.push(30);
  stack.push(3);
  stack.push(1);
  stack.Display();    
  auto end_time = high_resolution_clock::now();
  auto execution_time = duration_cast<microseconds>(end_time - start_time);
  cout << "Execution time: " << execution_time.count() << " us" << endl;
  return 0;
}
