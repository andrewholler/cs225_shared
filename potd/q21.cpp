#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Enter an integer: ";
    int n;
    cin >> n;

    int ** arr = new int *[n];
    for(int i = 0; i < n; i++){ // create 2D array
        arr[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = i + j;
            cout << arr[i][j] << " ";
            if(j == (n-1))
                cout << endl;
        }
    }
    return 0;
}
