#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int>> q;
vector<int> answer;
bool visited[101][101]; // 방문 여부를 확인할 visited 배열
int dx[4] = {0, 0, -1, 1}; // 행 이동
int dy[4] = {1, -1, 0, 0}; // 열 이동
int i, j, k, row, col, sum;

void bfs(vector<string> maps) {
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(maps[i][j] != 'X' && visited[i][j] == 0) {
                q.push({i, j});
                visited[i][j] = true;
                sum = maps[i][j] - '0';
                while(!q.empty()) {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    for(k = 0; k < 4; k++) {
                       int x = i + dx[k];
                       int y = j + dy[k];
                       if(x < 0 || y < 0 || x > (row - 1) || y > (col - 1)) continue;
                        
                       if(maps[x][y] != 'X' && visited[x][y] == 0) {
                           q.push({x, y}); // 상하좌우로 인접할 시, q에 push한다
                           visited[x][y] = true;
                           sum += (maps[x][y] - '0');
                       }
                    }
                } // while(상하좌우 인접한 무인도가 없을 때까지 while문 반복)
                answer.emplace_back(sum);
            }
        }
    } // for
}

vector<int> solution(vector<string> maps) {
    row = maps.size(); col = maps[0].length();
    
    bfs(maps);
    
    if(answer.empty()) { answer.emplace_back(-1); }
    sort(answer.begin(), answer.end());
    
    return answer;
}