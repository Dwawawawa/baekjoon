#include <iostream>

using namespace std;

    

int main()

{

    int ex[6] = {1, 5, 10, 20, 50, 100 };

    int arr[6];

    int sum[6]={0,0,0,0,0,0};

    

    

    

    for(int i =0; i <6; i++){

        cin >> arr[i];

        sum[i] = ex[i] * arr[i];

    }

    

    int max = sum[0];

    int size = 6;

    int fin = 0;

    // 배열의 모든 요소를 순회하며 최댓값 갱신

    for (int i = 1; i < size; i++) {

        if (sum[i] >= max) {

            max = sum[i];

            fin = i;

        }

    }

    //cout << max;

    cout << ex[fin];

    

    return 0;

}