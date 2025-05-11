#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m] {0};
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    ////출력 잘되는데;;
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < m; j++)
    //    {
    //        cout << arr[i][j] << " ";
    //    }cout << "\n";
    //}


    //행에 있는 9 체크하기 
    int* nCount = new int[n] {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = arr[i][j];

            while (temp > 0) {
                if (temp % 10 == 9) {
                    nCount[i]++;
                }
                temp /= 10;
            }
        }

        //cout << nCount[i] << " ";
    }

    //cout << "\n";

    //열에 있는 9 체크하기
    int* mCount = new int[m] {0};

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = arr[i][j];

            while (temp > 0) {
                if (temp % 10 == 9) {
                    mCount[j]++;
                }
                temp /= 10;
            }
        }

        //cout << mCount[j] << " ";
    }

    //cout << "\n";

    int max = 0;
    int sum = 0;


    for (int i = 0; i < n; i++) {
        if (nCount[i] > max) {
            max = nCount[i];
        }
        sum += nCount[i];
    }

    for (int i = 0; i < m; i++) {
        if (mCount[i] > max) {
            max = mCount[i];
        }


    }


    //cout << max;
    //cout << "\n";
    cout << sum - max;


    for (int i = 0; i < n; i++) {
        delete arr[i];
    }

    delete[] arr;
    delete[] nCount;
    delete[] mCount;
    return 0;
}
