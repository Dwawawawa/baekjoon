#include <iostream>
#include <string>
using namespace std;
int main() {
    int n1, n2;
    cin >> n1 >> n2;

    string group1, group2;
    cin >> group1 >> group2;
    int t;
    cin >> t;

    bool isGroup1[50] = { false };
    char ants[50];

    for (int i = 0; i < n1; i++) {
        ants[n1 - 1 - i] = group1[i];
        isGroup1[n1 - 1 - i] = true;
    }

    for (int i = 0; i < n2; i++) {
        ants[n1 + i] = group2[i];
        isGroup1[n1 + i] = false;
    }

    //cout << "초기 : ";
    //for (int i = 0; i < n1 + n2; i++) {
    //    cout << ants[i];
    //}
    //cout << endl;
    //cout << "초기 : ";
    //for (int i = 0; i < n1 + n2; i++) {
    //    cout << isGroup1[i];
    //}
    //cout << endl;


    for (int second = 0; second < t; second++) {
        for (int i = 0; i < n1 + n2 - 1; i++) {
            if (isGroup1[i] && !isGroup1[i+1]) {
                swap(ants[i], ants[i+1]);
                swap(isGroup1[i], isGroup1[i + 1]);
                i++;
                //cout << "바뀜 : ";
                //for (int i = 0; i < n1 + n2; i++) {
                //    cout << ants[i];
                //}
                //cout << endl;
                //cout << "바뀜 : ";
                //for (int i = 0; i < n1 + n2; i++) {
                //    cout << isGroup1[i];
                //}
                //cout << endl;
            }
        }
    }


    //cout << "최종 : ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << ants[i];
    }
    //cout << endl;



    return 0;
}