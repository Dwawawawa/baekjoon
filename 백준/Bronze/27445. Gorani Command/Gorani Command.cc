#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;

    cin >> r >> c;
    
    int rowMinIndex = 0 , columMinIndex = 0;
    int rowMin = 50, columMin = 50;
    for (int i = 1; i < r; i++) {
        int temp;
        cin >> temp;
        if (temp < rowMin) {
            rowMinIndex = i;
            rowMin = temp;
        }
    }
    
    for (int i = 1; i <=  c; i++) {
        int temp;
        cin >> temp;
        
        if (i == 1 && temp < rowMin) {
            rowMinIndex = r;
            rowMin = temp;
        }

        if(temp < columMin) {
            columMinIndex = i;
            columMin = temp;
        }
    }

    cout << rowMinIndex << " " << columMinIndex;

    return 0;
}