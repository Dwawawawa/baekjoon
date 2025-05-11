#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double* arr = new double[n];
    
    double result = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        result += pow(arr[i], 3.0);
    }
    result = cbrt(result);

    cout << fixed << setprecision(15) <<result;

    delete[] arr;
    return 0;
}
