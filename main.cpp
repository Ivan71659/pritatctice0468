#include <iostream>

using namespace std;

class node {
  public: 
    int data;
    node* next;
    node* prev;

    node(int data) {
      this->data = data;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class list {
  public: 
    node* head;
    node* tail;

    list () {
      head = nullptr;
      tail = nullptr;
    }

    void print () {
      node* current = head;
      while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
      }
      cout << "\n";
    }   

    void add_back (int data) {
      node* new_node = new node (data);
      if(tail == nullptr) { 
         head = new_node;
         tail = new_node;
      } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      } 
    }

    // Q1: Write a method to find the length of a doubly linked list.
    int method1 (){
      node* current = head;
      int counter = 0;
      while(current != nullptr){
        counter += 1; 
        current = current->next;
      }
      return counter;
    }

    // Q2: Write a method to return the reverse of a given linked list.
    list method2 (){
      node*current = tail;
      list output;
      while(current != nullptr){
        output.add_back (current->data);
        current = current->prev;
      }
      return output;
    }

    // Q3: Write a method to check if a linked list is a palindrome.
    bool method3 (){
      list reverse = method2();
      node*current1 = head;
      node*current2 = reverse.head;
      
      while(current1 != nullptr && current2 != nullptr){
        if(current1->data != current2->data){
          return false;
        }
        current1 = current1->next;
        current2 = current2->next;
      }

      return true;
    } 
};

int main () { 
  list test1;
  test1.add_back (1);
  test1.add_back (2);
  test1.add_back (3);

  list test2;
  test2.add_back (1);
  test2.add_back (2);
  test2.add_back (3);
  test2.add_back (2);
  test2.add_back (1);
  
  cout << "\nQuestion # 1:\n";
  cout << test1.method1 () << "\n";

  cout << "\nQuestion # 2:\n";
  test1.method2 ().print ();

  cout << "\nQuestion # 3:\n";
  cout << test1.method3 () << "\n";
  cout << test2.method3 () << "\n";
}
