#include <iostream>
#include <algorithm> // to use find()
using namespace std;

int T, tc, i, j, k, cycle=5, temp; // tc means test case
bool switch_value = true;
int num[8];

void Calculate() {
     switch_value = true;
    for(i = 0; i < 8; i++) {
    	cin >> num[i];
    }
    
    while(switch_value) {
    	for(j = 0; j < cycle; j++) {
            if(switch_value == false) {
                break;
            }
        	num[0]-=j+1;
            if(num[0] <= 0) {
                num[0] = 0;
            }
            temp = num[0];
            for(int k = 0; k < 7; k++) {
            	num[k] = num[k + 1];
            }
            num[7] = temp;
            
            int* check = find(num, num + 8, 0);
            if(check != num + 8) { // When there is 0 in the num array
                switch_value = false;
            }
        }
	}
    
    for(i = 0; i < 8; i++) {
    	cout << num[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char **argv) {

	while(cin >> tc) {
		cout << "#" << tc << " ";
		Calculate();
    }
    
	return 0;
}