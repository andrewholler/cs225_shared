#include <iostream>
#include <ctime>
using namespace std;

int main(){
    time_t now= time(0);
    double hours = now/3600;
    double years = now/60/525600;        //How do you measure a year? #rent
    cout << "Seconds: " << now << endl << "Hours: " << hours << endl << "Years: " << years << endl;
    return 0;
}
