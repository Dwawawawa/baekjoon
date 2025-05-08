#include <iostream>
using namespace std;

int Bingo[5][5];
bool bBingo[5][5];
bool bingoCount[12];
bool bWhenBingo() {
	int num;
	if (
		bBingo[num = 0][0] &&
		bBingo[num][1] &&
		bBingo[num][2] &&
		bBingo[num][3] &&
		bBingo[num][4]
		) {
		bingoCount[0] = true;
	}
	if(
		bBingo[num = 1][0] &&
		bBingo[num][1] &&
		bBingo[num][2] &&
		bBingo[num][3] &&
		bBingo[num][4]
	) {
		bingoCount[1] = true;
	}
	if (
		bBingo[num = 2][0] &&
		bBingo[num][1] &&
		bBingo[num][2] &&
		bBingo[num][3] &&
		bBingo[num][4]
		) {
		bingoCount[2] = true;
	}
	if (
		bBingo[num = 3][0] &&
		bBingo[num][1] &&
		bBingo[num][2] &&
		bBingo[num][3] &&
		bBingo[num][4]
		) {
		bingoCount[3] = true;
	}
	if (
		bBingo[num = 4][0] &&
		bBingo[num][1] &&
		bBingo[num][2] &&
		bBingo[num][3] &&
		bBingo[num][4]
		) {
		bingoCount[4] = true;
	}
	if (
		bBingo[0][num = 0] &&
		bBingo[1][num] &&
		bBingo[2][num] &&
		bBingo[3][num] &&
		bBingo[4][num]
		) {
		bingoCount[5] = true;
	}
	if (
		bBingo[0][num = 1] &&
		bBingo[1][num] &&
		bBingo[2][num] &&
		bBingo[3][num] &&
		bBingo[4][num]
		) {
		bingoCount[6] = true;
	}
	if (
		bBingo[0][num = 2] &&
		bBingo[1][num] &&
		bBingo[2][num] &&
		bBingo[3][num] &&
		bBingo[4][num]
		) {
		bingoCount[7] = true;
	}
	if (
		bBingo[0][num = 3] &&
		bBingo[1][num] &&
		bBingo[2][num] &&
		bBingo[3][num] &&
		bBingo[4][num]
		) {
		bingoCount[8] = true;
	}
	if (
		bBingo[0][num = 4] &&
		bBingo[1][num] &&
		bBingo[2][num] &&
		bBingo[3][num] &&
		bBingo[4][num]
		) {
		bingoCount[9] = true;
	}
	if (
		bBingo[0][0] &&
		bBingo[1][1] &&
		bBingo[2][2] &&
		bBingo[3][3] &&
		bBingo[4][4]
		) {
		bingoCount[10] = true;
	}
	if (
		bBingo[0][4] &&
		bBingo[1][3] &&
		bBingo[2][2] &&
		bBingo[3][1] &&
		bBingo[4][0]
		) {
		bingoCount[11] = true;
	}

	
	//for (auto & i : bBingo) {
	//	for (bool j : i) {
	//		cout << j << " ";
	//	}cout << "\n";
	//}

	int asd = 0;
	for (int i = 0; i < 12; i++) {
		//cout << bingoCount[i] << " ";

		if (bingoCount[i] == true) {
			asd++;
		}
	}
	//cout << "\n";


	return asd >= 3;
}

int main()
{
	for (auto & i : Bingo) {
		for (int & j : i) {
			cin >> j;
		}
	}

	//for (auto & i : Bingo) {
	//	for (int j : i) {
	//		cout << j << " ";
	//	}cout << "\n";
	//}

	int count = 0;
	int result = NULL;
	for (auto& i : bBingo) {
		for (int j = 0; j < 5;j++) {
			count++;
			int temp;
			cin >> temp;

			for (int k = 0; k < 25;k++) {
				if (temp == Bingo[k/5][k%5]) {
					bBingo[k / 5][k % 5] = true;
					break;
				}
			}

			//cout << count <<"번째 시도: 들어간 값은~ ";
			//cout << temp << "입니다.\n";
			if (result == NULL) {
				if (bWhenBingo()) {
					result = count;
				}
			}


		}
	}

	cout << result;

	return 0;
}
