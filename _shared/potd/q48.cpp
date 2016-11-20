#include <iostream>
using namespace std;

class Circle{
    private:
        double radius;
    public:
        double getRadius() const{return radius;}
        void setRadius(double newRadius){radius = newRadius;}
};

void print(const Circle& c){
    cout << "I am a circle. My radius is " << c.getRadius() << endl;
}

int main(){
    Circle c;
    c.setRadius(4.0);
    const Circle * ptr1 = &c;
    Circle * const ptr2 = &c;
    cout << "The radius is " << ptr1->getRadius() << endl;
    return 0;
}
