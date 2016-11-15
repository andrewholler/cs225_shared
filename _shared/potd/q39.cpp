#include <iostream>
#include <string>
using namespace std;

string reverse(string str){
    string copy = str;
    for(int i = 0; i < str.length(); i++)
        copy[str.length() - 1 - i] = str[i];
    return copy;
}

int main(){
    string result = reverse("522SC");
    cout << result << endl;
    result = reverse("SI");
    cout << result << endl;
    result = reverse("LOOC");
    cout << result << endl;
    return 0;
}

