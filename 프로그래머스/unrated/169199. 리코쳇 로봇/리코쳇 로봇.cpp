#include <string>
#include <vector> // utility(pair 클래스) 포함
#include <queue>
using namespace std;

int visit[100][100];
int cnt[100][100];
queue<pair<int, int>> q;
pair<int, int> v;
int dx[4] = {0, 0, 1, -1}; // 동, 서, 남 북
int dy[4] = {1, -1, 0, 0};
int i, j, k, m, n, row, col, Min;

int bfs(int i, int j, vector<string> board, int row, int col) {
    Min = 999999;
    for(m = 0; m < 100; m++ ) {
        for(n = 0; n < col; n++) {
            cnt[m][n] = Min;
        }
    }
    
    q.push({i, j});
    visit[i][j] = 1;
    cnt[i][j] = 0;
    
    while(!q.empty()) {
        v = q.front();
        int x = v.first;
        int y = v.second;
        q.pop();
        
        for(k = 0; k < 4; k++) {
            int gx = x;
            int gy = y;
            while(1) {
                gx = gx + dx[k];
                gy = gy + dy[k];
                if(gx < 0 || gx >= row || gy < 0 || gy >= col) break;
                if(board[gx][gy] == 'D') break;
            }
            gx = gx - dx[k];
            gy = gy - dy[k];
            
            if(visit[gx][gy] == 1) {
                continue;
            } else {
                visit[gx][gy] = 1;
                cnt[gx][gy] = min(cnt[gx][gy], cnt[x][y]+1);
                q.push({gx, gy});
            }
        }
    }
    
    for(m = 0; m < row; m++) {
        for(n = 0; n < col; n++) {
            if(board[m][n] == 'G') {
                if(cnt[m][n] == Min) {
                    return -1;
                } else {
                    return cnt[m][n];
                }
            }
        }
    }
}

int solution(vector<string> board) {
    int answer = 0;
    row = board.size();
    col = board[0].length();
    
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(board[i][j] == 'R') {
                answer = bfs(i, j, board, row, col);
            }
        }
    }
    
    return answer;
}