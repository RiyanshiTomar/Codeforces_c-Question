#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
   
    for(int k = 1; k <= t; ++k){
    int a;
    cin >> a;
    int arr[a];
    for(int i = 0; i < a; ++i){
    cin >> arr[i];
    }
    sort(arr, arr+a);
    bool possible = true;
    for(int i = 0; i < a-1; ++i){
            if((arr[i+1]- arr[i]) > 1){
               possible = false;
               break;
            }
        
    }

    if(possible){
    cout << "YES" << endl;
    }else{
    cout << "NO" << endl;
    }
    
}
return 0;
}