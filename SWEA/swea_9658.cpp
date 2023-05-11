/*
<230511>
SW Expert Academy 9658. 유효숫자 표기
*/

#include <iostream>
#include <string>
#include <cmath> // to use round()
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC; cin >> TC;
    
    for(int tc = 1; tc <= TC; tc++) {
    	string num; cin >> num;
        float A;
        int B = 0;
        string checkOP, checkOP2, answer;
        
        B = num.length() - 1;
        num.insert(1, ".");
        checkOP = num[0];
        
        A = stof(num);
        A = A * 10; // to round to the second place(nn.xxx)
        A = round(A);
        A = A / 10; // to return to its original form(n.xxx)
        
        answer = to_string(A);
        checkOP2 = answer[0];
        if((checkOP.compare("9") == 0) && (B > 1) && (checkOP2.compare("1") == 0)) {
        	B++; // 10^n -> 10^n+1
        	answer.replace(1,2, ".0"); // 10. -> 1.0
        }
        answer.erase(3);
        answer.append("*10^");
            
        cout << "#" << tc << " " << answer << B << "\n";
    }
    
	return 0;
}
