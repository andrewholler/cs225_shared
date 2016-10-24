#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int myhash(string str){     // many different hash fucntions acceptable, this is just an example
    int len = str.length();
    int sum = 0;
    for(int i = 0; i < str.length(); i++){
        sum += str[i] * len;
        len++;
    }
    return sum % 5;
}

int main(){
    cout << "State your question: ";
    string in;
    getline(cin, in);
    if(in.length() > 100 || in.length() <= 1){
        cout << "Input must be at least 1 characters and no more than 100 characters." << endl;
        return 1;
    }
    if(in[in.length()-1] != '?'){
        cout << "Input must end in a ?." << endl;
        return 1;
    }
    int val = myhash(in);
    cout << in << " hashed to value " << val << endl;
    if(val == 0)
        cout << "The outlook is bleak." << endl;
    else if(val == 1)
        cout << "The answer is most likely yes." << endl;
    else if(val == 2)
        cout << "Is today Tuesday? If yes, then yes! Otherwise, probably not." << endl;
    else if(val == 3)
        cout << "Most definitely!" << endl;
    else
        cout << "The future in unclear at the moment. Try again later." << endl;
    return 0;
}
