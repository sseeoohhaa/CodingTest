#include <string>
#include <iostream>
// #include <cstring> to use memset
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visit[11][11][4] = { false };
    int i, x, y, startX, startY;
    /*int ch[250][250];
    int size = sizeof(ch) / sizeof(ch[0]);
	for(int j = 0; j < size; j++) {
		memset(ch[j], 0, sizeof(int)*250);
    }*/
    
    x = 5; y = 5; // current x, y(visit배열 때문에 5, 5에서 시작)
    for(i = 0; i < dirs.length(); i++) {
        startX = x; // current start x
        startY = y; // current start y
        if(dirs[i] == 'U') { // UP(direction: 0)
            if(y + 1 > 10) continue;
            y++;
            if(visit[startX][startY][0] == false && visit[x][y][1] == false) {
                visit[startX][startY][0] = true;
                answer++;
            }
        } else if(dirs[i] == 'D') { // DOWN(direction: 1)
            if(y - 1 < 0) continue;
            y--;
            if(visit[startX][startY][1] == false && visit[x][y][0] == false) {
                visit[startX][startY][1] = true;
                answer++;
            }
        } else if(dirs[i] == 'R') { // RIGHT(direction: 2)
            if(x + 1 > 10) continue;
            x++;
            if(visit[startX][startY][2] == false && visit[x][y][3] == false) {
                visit[startX][startY][2] = true;
                answer++;
            }
        } else { // LEFT(direction: 3)
            if(x - 1 < 0) continue;
            x--;
            if(visit[startX][startY][3] == false && visit[x][y][2] == false) {
                visit[startX][startY][3] = true;
                answer++;
            }
        }
        
    }
    
    return answer;
}