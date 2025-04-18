#include <iostream>
using namespace std;

struct Person{
    int score;
    int cheongan;
    int jiji;
};
int cheongan_matrix[10][10];
int jiji_matrix[12][12];
int chk[1196];
Person people[1196];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // n 입력 sz, nC3 계산
    int n;
    cin >> n;

    //10x10---
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> cheongan_matrix[i][j];
        }
    }
    //12x12---
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> jiji_matrix[i][j];
        }
    }
    //사람들 정보 입력---
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> people[cnt].score >> s;

        people[cnt].cheongan = static_cast<int>(s[0] - '0');
        people[cnt].jiji = static_cast<int>(s[1] - 'A');

        int temp = people[cnt].jiji * 100 + people[cnt].cheongan * 10 + people[cnt].score;
        if (3 == chk[temp]) continue;
        chk[temp]++;
        cnt++;
    }


    int max = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            for (int k = j + 1; k < cnt; k++) {
                int sum = 0;
                sum += jiji_matrix[people[i].jiji ][people[j].jiji ]
                     + jiji_matrix[people[i].jiji ][people[k].jiji ]
                     + jiji_matrix[people[j].jiji ][people[k].jiji ];
                sum += cheongan_matrix[people[i].cheongan][people[j].cheongan ]
                    + cheongan_matrix[people[i].cheongan ][people[k].cheongan ]
                     + cheongan_matrix[people[j].cheongan ][people[k].cheongan ];
                sum += people[i].score + people[j].score + people[k].score;
                if (sum > max) max = sum;
            }
        }
    }

    cout << max;
    return 0;
}
