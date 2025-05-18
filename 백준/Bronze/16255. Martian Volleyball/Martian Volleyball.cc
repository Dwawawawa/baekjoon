#include <iostream>
#include <algorithm>
using namespace std;

class Match {
public:
    int winScore;
    int x;
    int y;
    int remainPointu;

    int minRemainingPointsUntilGameEnd() {

        // 게임이 이미 끝난 경우
        if ((x >= winScore && x - y >= 2) || (y >= winScore && y - x >= 2)) {
            return 0;
        }

        // 두 팀 중 높은 점수와 낮은 점수 확인
        int highScore = (x > y) ? x : y;
        int lowScore = (x > y) ? y : x;

        int scoreDiff = highScore - lowScore;

        // 세 가지 경우로 나눠서 처리:
        // 1. 높은 점수가 이미 목표 점수 이상인 경우 (연장전)
        if (highScore >= winScore) {
            // 2점 차이가 될 때까지 필요한 최소 점수
            return 2 - scoreDiff;  // 항상 2가 됨 (각 팀이 1점씩 얻는 경우)
        }

        // 2. 높은 점수가 목표 점수 바로 전이고, 리드하고 있는 경우
        else if (highScore == winScore - 1 && scoreDiff > 0) {
            // 높은 점수 팀이 1점만 더 얻으면 됨
            return 1;
        }

        // 3. 일반적인 경우
        else {
            // 목표 점수까지 남은 점수와 2점 차이를 만들기 위해 필요한 추가 점수
            int pointsToWinScore = winScore - highScore;
            int pointsForTwoPointLead = max(0, 2 - scoreDiff);

            // 둘 중 큰 값을 사용해야 함
            return max(pointsToWinScore ,pointsForTwoPointLead);
        }
    }

    void remainPoint() {
        remainPointu = minRemainingPointsUntilGameEnd();
    }
};

int main()
{
    int n;
    cin >> n;
    
 

    Match* a = new Match[n];
    for(int i = 0 ; i < n ;i++)
    {
        cin >> a[i].winScore >> a[i].x >> a[i].y;
        a[i].remainPoint();
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i].remainPointu << endl;
    }


    delete[] a;

    return 0;

}