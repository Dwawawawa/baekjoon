#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int L;
	string str;
	cin >> L;
	cin >> str;

	unsigned long sum = 0;
	for (int i = 0; i < L; i++)
	{
		sum += (str[i] - 'a' + 1) * pow(31, i);
	}
	cout << sum % 1234567891;


	return 0;
}