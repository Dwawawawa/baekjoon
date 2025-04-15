#include <iostream>
using namespace std;
int countArray[40320] = { 0, };
int num = 0;
int checkArr[101] = { 0, };
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void permutation(int* arr, int depth, int n) {
    if (depth == n)
    {
        for (int i = 0; i < 101 ;i++ ) {
            checkArr[i] = 0;
        }
        //cout << num << endl;
        //cout << "원래 순열 ";
        //for (int i = 0; i < n; i++) {
        //    cout << arr[i] << " ";
        //}cout << endl;

        int* addedArr = new int[n] {0, };
        int* add50Arr = new int[n] {0, };
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                addedArr[i] = arr[i];
            }
            else {
                addedArr[i] = arr[i] + addedArr[i - 1];
            }
            if (addedArr[i] <= 50) {
                add50Arr[i] = addedArr[i] + 50;
            }
            else
                add50Arr[i] = addedArr[i];
            //cout << "서로: " << addedArr[i] << "   50: " << add50Arr[i] << endl;
        }
        for (int i = 0; i < n; i++) {
            checkArr[add50Arr[i]]++;
            if (checkArr[add50Arr[i]] == 2) {
                countArray[num]++;
            }
            //cout << add50Arr[i] << " " << checkArr[add50Arr[i]] << endl;
        }

        
        num++;
        delete[] addedArr;
        delete[] add50Arr;
        
        

        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(arr[depth], arr[i]);
        permutation(arr, depth + 1, n);
        swap(arr[depth], arr[i]);
    }
}

int main() {
    int n;
    cin >> n;
    int* input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    permutation(input, 0, n);
    int max = 0;
    for (int a : countArray) {
        if (a > max) {
            max = a;
        }
        //cout << a << " ";
    }
    cout << max;
    delete[] input;
    return 0;
}