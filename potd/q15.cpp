#include <iostream>
#include <string>
using namespace std;

class Square{
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
        Square operator+(const Square & rhs);
        const Square & operator=(const Square & rhs);
};

Square::Square(){
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName){name = newName;}
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

Square Square::operator+(const Square & rhs){
    Square s;
    s.setName((*this).getName() + rhs.getName());
    s.setLength((*this).getLength() + rhs.getLength());
    return s;
}

const Square & Square::operator=(const Square & rhs){       // the default assignment will just copy the values from the rhs object to the lhs object, so the two objects would have pointers pointing to the same length, not their own separate lengths that are the same value
    if(this == &rhs){return (*this);}
    (*this).setName(rhs.getName());
    (*this).setLength(rhs.getLength());
    return (*this);
}

int main(){
    return 0;
}
