#include <iostream>
using namespace std;

int stairs(int n){
    if(n==1||n==0){
        return 1;
    }else if(n==2){
        return 2;
    }else{
        return stairs(n-1)+ stairs(n-2)+ stairs(n-3);
    }
    
    
}
int main() {
    int n, output;
    cin >> n;
    output=stairs(n);
    cout<< output <<endl;
}
