#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main(){
    cout << "Enter a string of uppercase and lowercase letters: ";
    string in;
    getline(cin, in);
    map<char, int> dict;
    for(int i = 0; i < in.length(); i++){
        dict[tolower(in[i])] += 1;
    }
    char best;
    int bestval = -1;
    for(map<char, int>::iterator it = dict.begin(); it != dict.end(); it++){
        if(it->second > bestval){
            bestval = it->second;
            best = it->first;
        }
        if(it->second == bestval){
            if(it->first < best)
                best = it->first;
        }
    }
    cout << "The most frequent character is " << best << endl;
    return 0;
}
