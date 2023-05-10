/*
<230510>
SW Expert Academy 3750. Digit sum
*/

#include <iostream>
#include <string>
using namespace std;

unsigned long long sum;

unsigned long long f(string num) {
    
    while(num.length() != 1) {
        sum = 0;
        for(int i = 0; i < num.length(); i++) {
            sum += num[i] - 48;
        }
        num = to_string(sum);
    }
    
    return stol(num);
}

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
    
    string n;
    unsigned long long result;
    
    int T; cin >> T;
    
    for(int tc = 1; tc <= T; tc++) {
        cin >> n;
        result = f(n);
        
    	cout << "#" << tc << " " << result << "\n";
    }
    return 0;
}