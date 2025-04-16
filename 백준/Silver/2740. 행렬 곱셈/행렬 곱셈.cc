#include<iostream>

using namespace std;

int main (){

    

    int N, M, K;

    

    cin >> N >> M;

    int** arrA = new int*[N];

    for(int i = 0; i < N;i++){

        arrA[i] = new int[M];

    }

    

    for(int i = 0; i < N;i++){

        for(int j = 0; j < M; j++){

            cin >> arrA[i][j];

        }

    }

    

    cin >> M >> K;

    

    int** arrB = new int*[M];

    for(int i = 0; i < M;i++){

        arrB[i] = new int[K];

    }

    

    for(int i = 0; i < M;i++){

        for(int j = 0; j < K; j++){

            cin >> arrB[i][j];

        }

    }

    

    

    int** arrC = new int*[N];

    for(int i = 0; i < N;i++){

        arrC[i] = new int[K];

    }

    

    

    

    for(int i = 0; i < N;i++){

        for(int j = 0; j < K; j++){

           arrC[i][j] = 0;

           for(int l = 0; l < M; l++){

               arrC[i][j] += arrA[i][l] * arrB[l][j];

           }

        }

    }

    

    

    

    for(int i = 0; i < N;i++){

        for(int j = 0; j < K; j++){

            cout << arrC[i][j] << " ";

        }

        cout << endl;

    }

    

    for(int i = 0; i < N;i++){

        delete[] arrA[i];

    }

    delete[] arrA;

   

    for(int i = 0; i < M;i++){

        delete[] arrB[i];

    }

    delete[] arrB;

    

    for(int i = 0; i < N;i++){

        delete[] arrC[i];

    }

    delete[] arrC;

    

    return 0;

}