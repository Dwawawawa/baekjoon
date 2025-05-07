#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int size;
    int front;
    int rear; 
    int count; // 총 인원
public:
    CircularQueue(int n) {
        size = n;
        queue = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }
	
    ~CircularQueue() {
        delete[] queue;
	}

    bool isFull() {
        return count == size;
    }

	bool isEmpty() {
        return count == 0;
	}


    void enqueue(int value) {
        if (isFull()) {
            cout << "꽉참\n";
            return;
        }

        rear = (rear + 1) % size;
        queue[rear] = value;
        count++;
    }

    int dequeue() {
		if (isEmpty()) {
			cout << "빔\n";
			return -1;
		}

        int value = queue[front] ;
        front = (front + 1) % size;
        count--;
        return value;
    }
};

void josephus(int n, int k, int* result) {
    CircularQueue cq(n);

    for (int i = 1; i <= n; i++ ) {
        cq.enqueue(i);
    }

    for (int i = 0; i < n; i++) { // n번 수행하는데...
        for (int j = 0; j < k-1; j++) {
            int person = cq.dequeue();
            cq.enqueue(person);
        }

        result[i] = cq.dequeue();
    }
}


int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int* result = new int[n] ;
        
    josephus(n, k, result);

    cout << "<";
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if(i != n - 1)
        {cout << ", ";}
    }
    cout << ">";

    delete[] result;

    return 0;
}