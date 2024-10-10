#include <string>
#include <vector>
#include <algorithm> // to use find()

using namespace std;

int step = 50; // 몇 단계인지 count
int cnt; // 각 단어에서 일치하는 알파벳 수 count
int word_len;
int visited[50];

bool cmp_word(string a, string b) {
    cnt = 0; // cnt reset
    for(int i = 0; i < word_len; i++) { // 각 단어의 알파벳 비교 과정
        if( (a.substr(i, 1)).compare(b.substr(i, 1)) == 0 ) {
            cnt++;
        }
    }
    if(cnt == word_len - 1) {
        return true;
    } else {
        return false;
    }
}

void dfs(string begin, string target, int j, vector<string> words) {
    
    if(step <= j) {
        return;
    }
    
    if(begin == target) { // target에 도달했을 시 dfs 탐색 종료
        step = min(step, j);
        return;
    }
    
    for(int i = 0; i < words.size(); i++) {
        if(!visited[i]) {
            if(cmp_word(begin, words[i])) { // 한 알파벳을 제외하고 나머지 알파벳이 일치한 경우
                visited[i] = 1; // 단어 방문 여부 check
                dfs(words[i], target, j+1, words);
                visited[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    word_len = words[0].length(); // 단어 길이
    
    if(find(words.begin(), words.end(), target) == words.end()) {
        step = 0; // 변환할 수 없는 경우
    } else { // 변환 시작
        dfs(begin, target, 0, words);
        // 만약 여기서 for문 -> dfs를 실행하면, 시작값을 begin부터 words[i]까지 바꿀 수가 없다.
    }
    
    return step;
}