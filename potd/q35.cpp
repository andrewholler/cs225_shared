#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outfile;
    outfile.open("test.txt");
    outfile << "This is one line of text!\nThis is another!";
    outfile.close();

    ifstream infile;
    infile.open("test.txt");
    string line;
    while(getline(infile, line)){
        cout << line << endl;
    }
    infile.close();

    return 0;
}
