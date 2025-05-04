#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string a1, a2;
    cin >> a1 >> a2;
    
    // 조건 1: 두 단어의 구성 문자가 동일한지 확인
    int b1[26] = {0};
    int b2[26] = {0};
    
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
    
    // 조건 2: 첫 글자와 마지막 글자가 동일한지 확인
    bool condition2 = (a1[0] == a2[0] && a1[n-1] == a2[n-1]);
    
    // 조건 3: 모음을 제거한 문자열이 동일한지 확인
    string c1 = "", c2 = "";
    
    for (int i = 0; i < n; i++) {
        if (a1[i] != 'a' && a1[i] != 'e' && a1[i] != 'i' && a1[i] != 'o' && a1[i] != 'u') {
            c1 += a1[i];
        }
        if (a2[i] != 'a' && a2[i] != 'e' && a2[i] != 'i' && a2[i] != 'o' && a2[i] != 'u') {
            c2 += a2[i];
        }
    }
    
    bool condition3 = (c1 == c2);
    
    // 모든 조건을 만족하는지 확인
    if (condition1 && condition2 && condition3) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}