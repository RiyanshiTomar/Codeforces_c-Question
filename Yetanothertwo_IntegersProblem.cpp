#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        int a, b;
        cin >> a >> b;

        int diff = a-b;
        if(diff < 0){
            diff = -diff;
        }

        int moves = diff/10;
        if(diff % 10 != 0){
            moves++;
        }

        cout << moves << endl;
        
    }
    return 0;
}