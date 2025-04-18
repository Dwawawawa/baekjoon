#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int skill;
    int cheongan;
    int jiji;
};

int cheongan_matrix[10][10];
int jiji_matrix[12][12];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 천간 관계 점수 입력
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> cheongan_matrix[i][j];
        }
    }
    
    // 지지 관계 점수 입력
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> jiji_matrix[i][j];
        }
    }
    
    // 이 문제에서 가능한 천간과 지지의 조합은 제한적입니다 (10천간 x 12지지 = 120가지)
    // 각 조합별로 최고 실력을 가진 사람들만 저장
    vector<vector<Person>> best_people(10, vector<Person>(12));
    vector<vector<bool>> has_person(10, vector<bool>(12, false));
    
    // 모든 사람의 정보를 읽되, 각 천간-지지 조합별로 최대 5명만 저장
    vector<Person> people;
    for (int i = 0; i < n; i++) {
        int skill;
        string ilju;
        cin >> skill >> ilju;
        
        int cheongan = ilju[0] - '0';
        int jiji = ilju[1] - 'A';
        
        // 이 사람의 정보 저장
        Person person = {skill, cheongan, jiji};
        people.push_back(person);
        
        // 천간-지지 조합에 대한 정보 갱신
        if (!has_person[cheongan][jiji] || person.skill > best_people[cheongan][jiji].skill) {
            best_people[cheongan][jiji] = person;
            has_person[cheongan][jiji] = true;
        }
    }
    
    // 전체 사람 중 실력 기준 상위 500명만 고려
    const int TOP_CANDIDATES = min(500, n);
    
    // 실력 기준으로 내림차순 정렬
    sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.skill > b.skill;
    });
    
    // 최대 점수 계산
    int max_score = 0;
    
    // 상위 실력자들만 고려
    const int actual_candidates = min(TOP_CANDIDATES, (int)people.size());
    
    for (int i = 0; i < actual_candidates; i++) {
        for (int j = i + 1; j < actual_candidates; j++) {
            for (int k = j + 1; k < actual_candidates; k++) {
                const Person& p1 = people[i];
                const Person& p2 = people[j];
                const Person& p3 = people[k];
                
                int score = p1.skill + p2.skill + p3.skill;
                score += cheongan_matrix[p1.cheongan][p2.cheongan];
                score += cheongan_matrix[p1.cheongan][p3.cheongan];
                score += cheongan_matrix[p2.cheongan][p3.cheongan];
                score += jiji_matrix[p1.jiji][p2.jiji];
                score += jiji_matrix[p1.jiji][p3.jiji];
                score += jiji_matrix[p2.jiji][p3.jiji];
                
                max_score = max(max_score, score);
            }
        }
    }
    
    // 특별한 조합들도 확인 (각 천간-지지 조합별 최고 실력자들)
    vector<Person> special_candidates;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            if (has_person[i][j]) {
                special_candidates.push_back(best_people[i][j]);
            }
        }
    }
    
    // 최대 120명이므로 완전 탐색 가능
    int special_size = special_candidates.size();
    for (int i = 0; i < special_size; i++) {
        for (int j = i + 1; j < special_size; j++) {
            for (int k = j + 1; k < special_size; k++) {
                const Person& p1 = special_candidates[i];
                const Person& p2 = special_candidates[j];
                const Person& p3 = special_candidates[k];
                
                int score = p1.skill + p2.skill + p3.skill;
                score += cheongan_matrix[p1.cheongan][p2.cheongan];
                score += cheongan_matrix[p1.cheongan][p3.cheongan];
                score += cheongan_matrix[p2.cheongan][p3.cheongan];
                score += jiji_matrix[p1.jiji][p2.jiji];
                score += jiji_matrix[p1.jiji][p3.jiji];
                score += jiji_matrix[p2.jiji][p3.jiji];
                
                max_score = max(max_score, score);
            }
        }
    }
    
    cout << max_score << endl;
    return 0;
}