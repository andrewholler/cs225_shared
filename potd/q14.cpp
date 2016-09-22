#include <iostream>
#include <string>
using namespace std;

class Square{
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
    private:
        string name;
        double * lengthptr;
};

Square::Square(){
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName){name = newName;};
void Square::setLength(double newVal){*lengthptr = newVal;}
string Square::getName() const {return name;}
double Square::getLength() const {return *lengthptr;}

Square::Square(const Square & other){
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square(){
    delete lengthptr;
}

int main(){
    Square a;
    Square b = a;
    Square c(a);
    return 0;
}
