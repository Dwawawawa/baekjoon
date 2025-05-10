#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	char* arr = new char[n];

	int counts[3] = { 0,};
	for (int i = 0; i < n; i++ ) {
		cin >> arr[i];

		if (arr[i] == 'B') { counts[0]++; }
		else if (arr[i] == 'S') { counts[1]++; }
		else if (arr[i] == 'A') { counts[2]++; }
	}

	if (counts[0] == counts[1] && counts[2] == counts[1]) {
		cout << "SCU";
	}
	else if (counts[0] > counts[1] && counts[0] > counts[2]) {
		cout << "B";
	}
	else if (counts[1] > counts[0] && counts[1] > counts[2]) {
		cout << "S";
	}
	else if (counts[2] > counts[0] && counts[2] > counts[1]) {
		cout << "A";
	}
	else if (counts[0] == counts[1] && counts[0] > counts[2]) {
		cout << "BS";
	}
	else if (counts[0] == counts[2] && counts[0] > counts[1]) {
		cout << "BA";
	}
	else if (counts[2] == counts[1] && counts[2] > counts[0]) {
		cout << "SA";
	}
	else {

	}


	delete[] arr;
	return 0;
}