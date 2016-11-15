#include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Enter a positive integer: " << endl;
    cin >> x;

    if(x < 1)
        cout << "Please enter a positive integer." << endl;
    else if(x == 1)
        cout << "1 is prime" << endl;
    else{
        int prime = -1;       // -1 not yet known, 0 not prime, 1 prime
        int count = 2;
        while(count < x && prime!=1){
            if(count > x/2 && prime == -1)  // we don't have to check once we pass x/2. why?
                prime = 1;
            if(x % count == 0){
                if(prime == -1)
                    prime = 0;
                cout << count << " ";
            }
            count++;
        }
        if(prime)
            cout << x << " is prime" << endl;
        else
            cout << "divide " << x << endl;
    }
    return 0;
}
