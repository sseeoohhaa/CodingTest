#include <string>
#include <vector>

using namespace std;

int network = 0;
int visited[200];

void dfs(int j, int k, vector<vector<int>> computers) {
    visited[j] = 1; // visited check
    for(int i = 0; i < k; i++) {
        if(!visited[i] && computers[j][i] == 1) {
            dfs(i, k, computers);
        }
    }
}

int solution(int num, vector<vector<int>> computers) {
    
    for(int i = 0; i < num; i++) {
        if(visited[i]) {
            continue;
        } else {
            dfs(i, num, computers); // i: 현재 탐색중인 컴퓨터
            network++;
        }
    }
    
    return network;
}