#include <iostream>
#include <string>
using namespace std;

class Food{
    protected:
        string name;
    public:
        Food(){name = "Food";}
        virtual void printColor(){cout << "Foods come in a variety of colors." << endl;}
};

class Fruit : public Food{
    public:
        Fruit(){name = "Fruit";}
        virtual void printColor(){cout << "Fruits come in a variety of colors." << endl;}
};

class SpecificFruit : public Fruit{
    private:
        string color;
    public:
        SpecificFruit(string newName, string newColor){
            name = newName;
            color = newColor;
        }
        virtual void printColor(){cout << "A " << name << " is " << color << "." << endl;}
};

void printColors(Food * arr, int size){
    for(int i = 0; i < size; i++){
        arr[i]->printColor();
    }
}

int main(){
    Food food;
    Fruit fruit;
    SpecificFruit banana("banana", "yellow");
    SpecificFruit strawberry("strawbetty", "red");

    Food * arr[4] = {&food, &fruit, &banana, &strawberry};
    
    printColors(arr, 4);

    return 0;
}
