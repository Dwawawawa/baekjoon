#include <iostream>
using namespace std;

int arrA[50][50];
int arrB[50][50];


void flip3x3(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arrA[x + i][y + j] = 1 - arrA[x + i][y + j];
		}
	}
}


int main()
{

	int n, m;
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			arrA[i][j] = row[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			arrB[i][j] = row[j] - '0';
		}
	}

	if (n < 3 || m < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(arrA[i][j] != arrB[i][j])
				{
					cout << "-1";
					return 0;
				}
			}
		}
		cout << "0";
		return 0;
	}


	int count = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			// 현재 위치의 원소가 다르면 3x3 영역 뒤집기
			if (arrA[i][j] != arrB[i][j]) {
				flip3x3(i, j);
				count++;
			}
		}
	}
	bool identical = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arrA[i][j] != arrB[i][j]) {
				identical = false;
				break;
			}
		}
		if (!identical) break;
	}

	if (identical) cout << count;
	else cout << "-1";


	return 0;
}

