#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int L;
	string str;
	cin >> L;
	cin >> str;
	
	unsigned long long sum = 0;
	unsigned long long power = 1;


	for (int i = 0; i < L; i++)
	{
		sum = (sum + (((unsigned long long)str[i] - 96) * power % 1234567891) % 1234567891) % 1234567891;
		power = (((power % 1234567891) * 31) % 1234567891) % 1234567891;
	}

	
	cout << sum;

	return 0;
}