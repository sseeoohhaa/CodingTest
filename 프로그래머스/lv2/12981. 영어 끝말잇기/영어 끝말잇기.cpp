#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(int n, vector<string> words) {
    //vector<int> answer;
    
    int i;
    int size = words.size();
    string word, comp_word;
    int num, turn;
    bool flag;
    
    for(i = 1; i < size; i++) {
        word = words[i];
        comp_word = words[i-1];
        flag = true;
        
        if(find(words.begin(), words.begin() + (i-1), word) != words.begin() +(i-1)) {
            flag = false;
        } else if(word[0] != comp_word[comp_word.length()-1]) {
            flag = false;
        }
        
        if(i == size-1 && flag == true) {
            return {0,0};
        } else if(flag == false) {
            if(((i + 1) % n) == 0) {
                num = n;
            } else {
                num = (i + 1) % n;
            }
            
            if(((i + 1) % n) == 0) {
                turn = (i + 1) / n;
            } else {
                turn = (i + 1) / n + 1;
            }
                
            return{num, turn};
            break;
        }
    }

    //return answer;
}