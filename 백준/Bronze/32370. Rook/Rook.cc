#include <iostream>
using namespace std;

int main() {
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int count;


    if (ax != 0 && ay != 0) count = 2;
    else if (ax == 0 && ay == 0) count = 0; // 물론 조건상 불가능하다.
    else {
        if (ax == 0 && bx == 0 && ay > by) {
            count = 3;
        }
        else if (ay == 0 && by == 0 && ax > bx) {
            count = 3;
        }
        else {
            count = 1;
        }
    }

    cout << count;

    return 0;
}