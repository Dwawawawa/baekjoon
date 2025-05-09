#include <iostream>
using namespace std;


int main() {
	double z, x, c;
	cin >> z >> x >> c;

	double result;
	if (x > c) {
		result = z * x / c;
		
	}
	else {
		result = z / x * c;
	}
	cout << static_cast<int>(result);

	return 0;
}