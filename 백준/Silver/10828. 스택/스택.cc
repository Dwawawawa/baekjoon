#include <iostream>
using namespace std;

class Stack
{
    int* arr;
    int capacity;
    int top;
public:
    Stack(int size = 10000) 
    { 
        arr = new int[size];
        capacity = size;
        top = -1; 
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isFull() 
    {
        if (top == capacity) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isEmpty() 
    {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(int input) 
    {
        if (!isFull()) { 
            top++;
            arr[top] = input;
        }
        else {
            std::cout << "꽉참" << endl;
        }
    }

    void pop() 
    {
        if (!isEmpty()) {
            std::cout << arr[top]<<endl;
            arr[top] = NULL;
            top--;
        }
        else {
            std::cout << "-1" << endl;
        }
    }

    void empty() 
    {
        if (!isEmpty()) {
            std::cout << "0" << endl;
        }
        else {
            std::cout << "1" << endl;
        }
    }

    void size() 
    {
        std::cout << top + 1 << endl;
    }


    void checkTop()
    {
        if(!isEmpty())
        {
            std::cout << arr[top] << endl;
        }
        else {
            std::cout << "-1" << endl;
        }
    }
};



int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    Stack stack;
    string str;
    int input;
    for (int i = 0; i < n; i++) 
    {
        cin >> str;
        if (str == "push") {
            cin >> input;
            stack.push(input);
        }
        else if (str == "pop") {
            stack.pop();
        }
        else if (str == "size") {
            stack.size();
        }
        else if (str == "empty") {
            stack.empty();
        }
        else if (str == "top") {
            stack.checkTop();
        }

    }


    return 0;
}