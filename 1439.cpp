#include <iostream>
#include <string>
using namespace std;


int main()
{
	string zeroone;
	 
	cin >> zeroone;

	int count = 0;
	for (int i = 1; i < zeroone.size(); i++) {
		if (zeroone[i] == zeroone[i - 1]) {

		}
		else if (zeroone[i] != zeroone[i - 1]) {
			count++;
		}
	}


	cout << (count + 1) / 2;

	return 0;
}

