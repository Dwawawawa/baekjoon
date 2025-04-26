#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int capacity;
    int top;
public:
    Stack(int size = 1000000) { 
        arr = new int[size];
        capacity = size;
        top = -1; 
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    bool isFull() {
        return top == capacity - 1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    void push(int input) {
        if (!isFull()) { 
            top++;
            arr[top] = input;
        }
    }
    
    void pop() {
        if (!isEmpty()) {
            cout << arr[top] << '\n';
            top--;
        }
        else {
            cout << "-1" << '\n';
        }
    }
    
    void empty() {
        cout << (isEmpty() ? "1" : "0") << '\n';
    }
    
    void size() {
        cout << top + 1 << '\n';
    }
    
    void checkTop() {
        if (!isEmpty()) {
            cout << arr[top] << '\n';
        }
        else {
            cout << "-1" << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    Stack stack;
    
    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;
        
        if (cmd == 1) {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (cmd == 2) {
            stack.pop();
        }
        else if (cmd == 3) {
            stack.size();
        }
        else if (cmd == 4) {
            stack.empty();
        }
        else if (cmd == 5) {
            stack.checkTop();
        }
    }
    
    return 0;
}