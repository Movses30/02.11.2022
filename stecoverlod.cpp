#include <iostream>
#include <cassert>
using namespace std;

template <typename T> 
class Stack {
private:
    T* array;
    int count;
    int allocation_size;


    void resizeArray();
public:
    Stack(int capacity = 4);
    ~Stack();
    
    // Copy constructor
    Stack(const Stack<T>& stk);

    // Assignment operator
    Stack<T>& operator = (const Stack<T>& stk);


    void push(const T& val);

    void pop(T& val);

    T& top();

    bool isEmpty();

    int size();

    void displayAll();

    void clearAll();
};

template <typename T>
Stack<T>::Stack(int capacity) {
    array = new T[capacity];
    allocation_size = capacity;
    count = 0;
}

template <typename T>
Stack<T>::~Stack() {
    delete array;
}

// @brief Copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& stk) {
   // TODO: Add you code here
   allocation_size = stk.allocation_size;
   array = new T[allocation_size];
   count = stk.count;
   for (int i = 0; i < count; i++){
       array[i] = stk.array[i];
   }
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& stk) {
  // TODO: Add you code here
  delete array;
  allocation_size = stk.allocation_size;
  array = new T[allocation_size];
  count = stk.count;
  for (int i = 0; i < count; i++){
      array[i] = stk.array[i];
  }

  return *this;
  
}
template <typename T>
void Stack<T>::resizeArray() {
    T* new_array = new T[allocation_size * 2];
    for (int i = 0; i < count; i++) {
        new_array[i] = array[i];
    }
    allocation_size *= 2;
    delete[] array;
    array = new_array;
}

// @brief Push a value to the stack.
template <typename T>
void Stack<T>::push(const T& val) {
   // TODO: Add your code here
    array[count] = val;
    count++;
}

// @brief If not empty, removes and gives back the top element;
template <typename T>
void Stack<T>::pop(T& val) {
    // TODO: Add your code here
    --count;
    val = array[count];
}

// @brief Returns a reference to the top most element of the stack
template <typename T>
T& Stack<T>::top() {
    // TODO: Add your code here
    return array[count];
}

// @brief Check if the stack is empty
template <typename T>
bool Stack<T>::isEmpty() {
    // TODO: Add your code here
    return count < 0;
}

// @brief Returns the number of elements in the stack
template <typename T>
int Stack<T>::size() {
    // TODO: Add your code here
    return count;
}

// @brief Display the content of the stack
template <typename T>
void Stack<T>::displayAll() {
    if (count == 0) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = 0; i < count; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    cout << "Create a new stack" << endl;
    Stack <int> stack;
   // assert(stack.size() == 0);
    cout << "push 1,  stack = " << endl;
    stack.push(1);
    stack.displayAll();

    // Test push function
    for(int i = 0; i < 10; i++) {
        stack.push(i);
        cout << "push " << i << ", stack = ";
        stack.displayAll();
    }


    // Test pop function
    for (int i = 0; i < 5; i++) {
        int x;
        stack.pop(x);
        cout << "pop top val = " << x << ", stack = ";
        stack.displayAll();
    }


    // Test copy constructor 
    cout << "Test copy constructor, s2 as a copy of stack" << endl;
    Stack<int> s2(stack);
    cout << "s2 size = " << s2.size() << endl;
    cout << "s2 = ";
    s2.displayAll();


    
}