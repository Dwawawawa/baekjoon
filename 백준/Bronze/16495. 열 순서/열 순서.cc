#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main()
{


	string str;
	unsigned long long n = 0;
	cin >> str;

	int digit = str.length();
	

	for (char c : str) {
		digit--;
		n += static_cast<unsigned long long>(pow(26, digit)) * static_cast<unsigned long long>(static_cast<int>(c) - 'A' + 1);
		
	}
	cout << n;
	return 0;
}

