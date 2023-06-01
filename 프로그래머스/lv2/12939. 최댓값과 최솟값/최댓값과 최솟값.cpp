#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp, k, max, min;
    int len = s.length();
    int i, j, n;
    vector<int> num;
    
    for(i = 0; i < len; i++) {
        tmp.clear();
        if(s[i] == ' ') {
            continue;
        } else if(s[i] == '-') {
            tmp.append("-");
            while(s[i+1] != ' ') {
                tmp+= s[i+1];
                i++;
            }
            n = stoi(tmp);
        } else {
            k+= s[i];
            while(s[i+1] != ' ' && i+1 < len) {
                k+= s[i+1];
                i++;
            }
            n = stoi(k);
            k.clear();
        }
        num.emplace_back(n);
    }
    sort(num.begin(), num.end());
    min = to_string(num[0]);
    max = to_string(num[num.size() - 1]);
    
    answer.append(min + ' ' + max);
    return answer;
}