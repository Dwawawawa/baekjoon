#include <iostream>
using namespace std;

int arr[100];
int main() {
    int n, v, e ;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v >> e;
        arr[i] = 2 + e - v;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}