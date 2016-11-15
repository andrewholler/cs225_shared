#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    ifstream infile;
    infile.open("text.txt");
    string line;
    while(getline(infile, line)){
        if(-1 != line.find("purple")){
            cout << line << endl;
        }
    }

    infile.close();

    return 0;
}
