#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s) {
    bool answer = true;
    bool flag = true;
    int i;
    stack<char> stack;
    
    for(i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            stack.push(s[i]);
            flag = false;
        }
        if(s[i] == ')' && stack.size() == 0) {
            answer = false;
        }
        if(s[i] == ')' && stack.size() > 0) {
            stack.pop();
        }
    }
    
    if(stack.size() > 0) {
        answer = false;
    }
    if(flag) {
        answer = false;
    }

    return answer;
}