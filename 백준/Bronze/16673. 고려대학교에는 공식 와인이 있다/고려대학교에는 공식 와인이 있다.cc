#include <iostream>
using namespace std;

int main()
{
    int n , k , p ; 
    cin >> n >> k >> p;
    
    int res = 0;

    for (int i = 1; i <= n; i++) {
        res += i * k + i * i * p;
    }

    cout << res;

    return 0;

}