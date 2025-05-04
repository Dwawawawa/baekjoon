#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	string a1, a2;
	cin >> n >> a1 >> a2;
	
	// 1번째 조건
	int b1[26] = { 0 };
	int b2[26] = { 0 };
	for (int i = 0; i < n; i++) { 
		b1[a1[i] - 'a']++;
		b2[a2[i] - 'a']++;
	}

	bool condition1 = true;
	for (int i = 0; i < 26; i++) {
		if (b1[i] != b2[i]) {
			condition1 = false;
			break;
		}
	}

	bool condition2 = (a1[0] == a2[0] && a1[n - 1] == a2[n - 1]);

	string c1 = "", c2 = "";

	for (int i = 0; i < n; i++) { // 3번쨰 조건
		if (a1[i] != 'a' &&
			a1[i] != 'e' &&
			a1[i] != 'i' &&
			a1[i] != 'o' &&
			a1[i] != 'u') {
			c1 += a1[i];
		}

		if (a2[i] != 'a' &&
			a2[i] != 'e' &&
			a2[i] != 'i' &&
			a2[i] != 'o' &&
			a2[i] != 'u') {
			c2 += a2[i];
		}
	}
	bool condition3 = (c1 == c2);

	

	if (condition1 && condition2 && condition3)
		cout << "YES";
	else cout << "NO";

	

	return 0;

}