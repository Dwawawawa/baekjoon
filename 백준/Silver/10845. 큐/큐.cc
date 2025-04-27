#include <iostream>
using namespace std;

class Queue  // 일반 큐
{   
    int* arr;
    int capacity;
    int front;
    int rear;
public:
    Queue(int size = 10000) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear + 1 == front;
    }

    void push(int input) {        
        
        rear++;
        arr[rear] = input;
    }

    void pop() {        
		if(!isEmpty())
        {
			cout << arr[front] << '\n';
			front++;
		}
        else{ cout << "-1" << '\n'; }
    }

    void empty() {
        cout << (isEmpty() ? "1" : "0") << '\n';
    }

    void Size() {
        cout << rear - front + 1 << '\n';
    }

	void checkFront() {
		if (!isEmpty()) {
			cout << arr[front] << '\n';
		}
		else {
			cout << "-1" << '\n';
		}
	}


    void checkRear() {
        if (!isEmpty()) {
            cout << arr[rear] << '\n';
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
    Queue stack;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (cmd == "pop") {
            stack.pop();
        }
        else if (cmd == "size") {
            stack.Size();
        }
        else if (cmd == "empty") {
            stack.empty();
        }
		else if (cmd == "front") { //미완
			stack.checkFront();
		}
        else if (cmd == "back") { //미완
            stack.checkRear();
        }
    }

    return 0;
}