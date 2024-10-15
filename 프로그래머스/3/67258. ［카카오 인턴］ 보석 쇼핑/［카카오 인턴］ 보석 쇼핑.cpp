#include <string>
#include <vector>
#include <algorithm> // to use sort()
#include <map> // to use map

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map <string, int> gem;
    vector<string> gemType = gems; // 바로 복사 가능
    
    // 보석 종류(개수) count
    sort(gemType.begin(), gemType.end());
    gemType.erase(unique(gemType.begin(), gemType.end()), gemType.end());
    
    int uniqueGemCount = gemType.size();
    int currentGemCount = 0;
    
    int start, end, min_length, last;
    last = gems.size(), min_length = last + 1;
    start = 0, end = 0;
    while(end < last) {
        // 1. 모든 보석을 찾기까지 과정(ex: SAPPHIRE)
        if(gem[gems[end]]++ == 0) { // 새로운 보석인지 확인 후 count, 각 보석의 개수를 ++
            currentGemCount++;
        }
        end++; // 한 칸씩 넘어간다는 것을 의미
        
        // 2. 가장 짧은 구간을 찾는 과정(ex: DIA -> RUBY -> RUBY 2)
        while(currentGemCount == uniqueGemCount) { // 모든 보석을 찾은 경우
            if(min_length > end-start) {
                min_length = end-start;
                answer = { start + 1, end };
            }
            // 더 이상 한 종류의 보석이라도 포함되지 않게 될 경우
            if (--gem[gems[start]] == 0) {
                currentGemCount--;
            }
            start++;
        }
    } // while
    
    return answer;
}