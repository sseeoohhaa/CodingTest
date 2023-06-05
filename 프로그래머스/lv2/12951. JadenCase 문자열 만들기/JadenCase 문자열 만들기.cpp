#include <string>
#include <vector>
// #include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int i = 0;
    int len = s.length();
    
    while(i < len) {
        if(isalpha(s[i]) == 0 && s[i] != ' ') {
            while(isspace(s[i]) == 0 && i < len) {
                s[i] = tolower(s[i]);
                i++;
            }
        } else if(isupper(s[i]) != 0) {
            i++;
            while(isspace(s[i]) == 0 && i < len) {
                s[i] = tolower(s[i]);
                i++;
            }
        } else if(islower(s[i]) != 0) {
            s[i] = toupper(s[i]);
            i++;
            while(isspace(s[i]) == 0 && i < len) {
                s[i] = tolower(s[i]);
                i++;
            }
        }
        i++;
    }
    
    answer = s;
    return answer;
}