#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int r, c, k, i, j, m, n, rlen, clen, tm, ans;
    int A[101][101];
    int C[101]; // 1~100 number count
    vector<pair<int, int>> v; // 정렬을 위한 (수, 수의 등장 횟수)를 담는 pair vector
    vector<int> s; // to calculate row, col length
    cin >> r >> c >> k;
    
    /* reset A arr -> 줄어드는 경우 catch(x)
    for(int i = 0; i < 101; i++) {
	    fill(A[i], A[i] + 101, 0);                     
    } */
    
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3; j++) {
            cin >> A[i][j];
        }
    }
    
    rlen = 3; // row length
    clen = 3; // col length
    
    tm = 0; // time
    while(1) {
        if(A[r][c] == k) {
            ans = tm;
            break;
        }
        if(tm > 100) {
            ans = -1;
            break;
        }
        
        if(rlen >= clen) { // R 연산
            for(i = 1; i <= rlen; i++) {
                fill_n(C, 101, 0); // reset
                v.clear();
                for(j = 1; j <= clen; j++) {
                    C[A[i][j]]++;
                }
                for(j = 1; j < 101; j++) {
                    if(C[j] != 0) {
                        v.emplace_back(make_pair(C[j], j));
                    } else { continue; }
                }
                sort(v.begin(), v.end());
                for(j = 1; j <= clen; j++) {
                    A[i][j] = 0; // reset A arr
                }
                n = 1;
                for(j = 0; j < v.size(); j++) {
                    A[i][n++] = v[j].second;
                    A[i][n++] = v[j].first;
                }
                n--; // 마지막 n++ 연산 제외해주기
                s.emplace_back(n);
            }
            sort(s.begin(), s.end());
            clen = s.back();
        } else { // C 연산
            for(i = 1; i <= clen; i++) {
                fill_n(C, 101, 0); // reset
                v.clear();
                for(j = 1; j <= rlen; j++) {
                    C[A[j][i]]++;
                }
                for(j = 1; j < 101; j++) {
                    if(C[j] != 0) {
                        v.emplace_back(make_pair(C[j], j));
                    } else { continue; }
                }
                sort(v.begin(), v.end());
                for(j = 1; j <= rlen; j++) {
                    A[j][i] = 0; // reset A arr
                }
                n = 1;
                for(j = 0; j < v.size(); j++) {
                    A[n++][i] = v[j].second;
                    A[n++][i] = v[j].first;
                }
                n--;
                s.emplace_back(n);
            }
            sort(s.begin(), s.end());
            rlen = s.back();
        }
        s.clear();
        tm++;
    } // while
    
    cout << ans;
    return 0;
}