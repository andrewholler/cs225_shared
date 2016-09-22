#include <iostream>
#include <cmath>
using namespace std;

int main(){
    char input;
    do{
        cout << "Enter 'c' for cosine, 's' for sine, or 'q' to quit." << endl;
        cin >> input;
        if(input == 'q'){return 0;}
    } while(input != 's' && input != 'c');
    double val;
    cout << "Enter a number." << endl;
    cin >> val;
    if(input == 'c'){cout << cos(val) << endl;}
    else{cout << sin(val) << endl;}
    return 0;
}
