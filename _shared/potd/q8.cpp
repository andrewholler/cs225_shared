#include <iostream>
using namespace std;

int main(){
    char * x = new char[5];
    x[0] = 'h';
    x[1] = 'e';
    x[2] = 'l';
    x[3] = 'l';
    x[4] = 'o';
    char ** y = &x;
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += x[i];
    }
    cout << "The value of y is " << y << endl;
    cout << "The sum of the characters is " << sum << endl;
    delete [] x;

    return 0;
}
