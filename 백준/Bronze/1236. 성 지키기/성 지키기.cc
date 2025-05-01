#include <iostream>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    bool** arr = new bool* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new bool[m];
    }


    char temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;

            if(temp == '.')
            {
                arr[i][j] = false;
            }
            else if (temp == 'X')
            {
                arr[i][j] = true;
            }
        }
    }

    int rowCount = n;
    int columCount = m;

    //행체크
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j])//true가 하나라도 있으면...
            {
                rowCount--;
                break;
            }
        }
    }
    
    
    //열체크
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {    
            if (arr[i][j])//true가 하나라도 있으면...
            {
                columCount--;
                break;
            }
        }
    }

    cout << ((rowCount > columCount) ? rowCount : columCount);

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}