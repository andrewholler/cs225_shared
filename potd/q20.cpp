#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'y' || c == 'Y')
        return true;
    else
        return false;
}

int main(){
    while(1){
        cout << "Enter a word you would like translated: ";
        string in;
        cin >> in;
        if(!in.compare("q"))
            return 0;
        for(int i = 0; i < in.length(); i++){
            if(i == 0 && isVowel(in[i])){
                cout << in + "ay" << endl;
                break;
            }
            if(isVowel(in[i])){
                string prefix = in.substr(0, i);
                string suffix = in.substr(i, in.length() - i);
                cout << suffix + prefix + "ay" << endl;
                break;
            }
            if(i == in.length() - 1){
                cout << in + "ay" << endl;
                break;
            }
        }
    }
}

