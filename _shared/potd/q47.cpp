#include <iostream>
using namespace std;

#define COLOR "purple"
#define IAMDEFINED
// header guards are wrapping your header file class definitions in statments like:
// #ifndef MYHEADER_H
// #derine MYHEADER_H
// class definition
// #endif
// Using header guards prevents the redefinition of functions and classes if you were to accidentally include the header file twice

int main(){
    #ifdef IAMDEFINED
    cout << COLOR << " is a cool color" << endl;
    #endif    
    return 0;
}
