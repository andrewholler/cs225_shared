#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int A = 65;

// runtime is O(n)

string testshift(string message, int shift){
    string copy = message;
    for(int i = 0; i < message.length(); i++){
        if(copy[i] == 32)       // check if space
            continue;
        copy[i] = (((copy[i] - A) + shift) % 26) + A;   // get character into range 0-25, add shift amount, mod 26 to remain in range 0-25, shift back into range 65-90
    }
    return copy;
}

bool check(string message){
    if(message.find("POP QUIZ") != -1)
        return true;
    else
        return false;
}

int main(){
    ifstream infile;
    infile.open("encrypted.txt");
    ofstream outfile;
    outfile.open("decrypted.txt");
    string message, decrypted;
    getline(infile, message);
    for(int i = 0; i < 26; i++){
        decrypted = testshift(message, i);
        if(check(decrypted)){
            outfile << decrypted;
            return 0;
        }
    }
    cout << "You must have intercepted the wrong message" << endl;
    return 0;
}

