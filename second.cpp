#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
  public:
    int data;
    Node* next;

    Node(int value) {
      data = value;
      next = nullptr;
    }
};

class Stack {
  private:
    Node* t;

  public:
    Stack() {
      t = nullptr;
    }

    bool push(int p) {
      Node* newNode = new Node(p);
      if (newNode == nullptr) {
        cout << "Error: memory allocation failed\n";
        return false;
      } else {
        newNode->next = t;
        t = newNode;
        cout << p << " push to stack\n";
        return true;
      }
    }

    int pop() {
      if (isEmpty()) {
        cout << "Error: stack underflow\n";
        return 0;
      } else {
        int p= t->data;
        Node* temp = t;
        t = t->next;
        delete temp;
        return p;
      }
    }

    bool isEmpty() {
      return (t == nullptr);
    }

    int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return t->data;
      }
    }

    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack: ";
        Node* current = t;
        while (current != nullptr) {
          cout << current->data << " ";
          current = current->next;
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
